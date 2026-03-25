#pragma once
#include<iostream>
using namespace std;
namespace key
{
	template<class K>
	struct BSTNode//树节点
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

		BSTNode(const K& key)
			:_key(key)
			,_left(nullptr)
			,_right(nullptr)
		{ }
	};

	template<class K>
	class BSTree
	{
		using Node = BSTNode<K>;//和typedef Node = BSTNode<K>;一样的作用	
	public:
		//插入
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			//找位置
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key<key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
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

		//查找
		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		//删除
		bool Erase(const K& key)
		{
			if (Find(key)==0)
				return false;

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				//查找
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//删除	
					if (cur->_left == nullptr)//被删节点左为空的情况
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)//在父亲的左边
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
					else if (cur->_right == nullptr)//被删节点右为空的情况
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
						//左右都不为空
						//找右子树最左节点
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;

						if (replaceParent->_left == replace)
							replaceParent->_left = replace->_right;
						else
							replaceParent->_right = replace->_right;

						delete replace;
					}
					return true;
				}
			}
			return false;
		}






		//打印
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}

	private:
		Node* _root = nullptr;

	private:
		void _Inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			//中序遍历打印
			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}
	};

}