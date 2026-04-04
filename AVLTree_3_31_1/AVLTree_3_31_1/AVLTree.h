#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K,V>* _parent;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _left;
	pair<K,V> _kv;
	int _bf;

	AVLTreeNode(const pair<K,V>& kv)
		:_parent(nullptr)
		,_right(nullptr)
		,_left(nullptr)
		,_kv(kv)
		,_bf(0)
	{ }
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
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
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right= cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//控制平衡，更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 || cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 || cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		//记录父亲的父亲节点
		Node* Pparent = parent->_parent;

		subL->_right = parent;
		parent->_parent=subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (Pparent->_left == parent)
			{
				Pparent->_left = subL;
			}
			else
			{
				Pparent->_right = subL;
			}
			subL->_parent = Pparent;
		}
		//更新平衡因子
		parent->_bf = subL->_bf= 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* Pparent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (Pparent == nullptr)
		{
			_root=subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (Pparent->_left == parent)
			{
				Pparent->_left = subR;
			}
			else
			{
				Pparent->_right = subR;
			}
			subR->_parent = Pparent;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		//提前记录平衡因子
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf =1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	//查找
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
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

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	int Size()
	{
		return _Size(_root);
	}

	//高度
	int Height()
	{
		return _Height(_root);
	}

	//判断是否为AVL树
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:
	Node* _root = nullptr;

	void _Inorder( Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	bool _IsBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		if (abs(diff) >= 2)
		{
			cout << "高度差异常" << endl;
			return false;
		}
		if (root->_bf != diff)
		{
			cout << "平衡因子异常" << endl;
			return false;
		}

		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}
};