#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
enum Colour
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{ }
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	//插入
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//找空位
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)

			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//插入
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first<kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//如果父亲节点是红色，需要处理
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//情况1
				{
					parent->_col = uncle->_col = BLACK;				
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left= subLR;
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}

	Node* Find(const K&key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first <key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;

		if (_root->_col == RED)
			return false;

		int ref = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++ref;
			}
			cur = cur->_left;
		}
		return Check(_root, 0, ref);
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;

	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr)
		{
			//到达叶子节点
			if (refNum != blackNum)
			{
				cout << "存在黑色节点数量不相等的路径" << endl;
				return false;
			}
			return true;
		}
		//检查是否有连续的红色节点
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续红色结点" << endl;
			return false;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}
		return Check(root->_left, blackNum, refNum) &&
			Check(root->_right, blackNum, refNum);

	}
	void _inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_inorder(root->_right);
	}

};