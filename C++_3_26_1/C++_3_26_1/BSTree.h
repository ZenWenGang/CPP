#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(nullptr)
		,_right(nullptr){ }
	K _key;
	V _value;
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree() = default;
	~BSTree()
	{
		Destroy(_root);
		_root = nullptr;
	}
	BSTree(const BSTree& root)
	{
		_root=_Copy(root._root);
	}
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			//ÕÒ¿ÕÎ»
			if(cur->_key<key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
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
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			//ÕÒÎ»ÖÃ
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//É¾³ý
				if (cur->_left==nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else
				{
					Node* replace = cur->_right;
					Node* replaceParent = cur;
					while (replace->_left)
					{
						replaceParent = replace;
						replace = replace->_left;
					}
					cur->_key = replace->_key;
					if (replaceParent->_left == replace)
					{
						replaceParent->_left = replace->_right;
					}
					else
					{
						replaceParent->_right = replace->_right;
					}
					delete replace;
				}
				return true;
			}
		}
		return false;
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}
	Node* _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newnode = new Node(root->_key, root->_value);
		newnode->_left = _Copy(root->_left);
		newnode->_right = _Copy(root->_right);
		return newnode;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " " << ":" << root->_value << endl;
		_InOrder(root->_right);
	}
};

