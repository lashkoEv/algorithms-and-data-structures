#pragma once


#include <iostream>
using namespace std;

template<class T>
class BinaryTree
{
private:
	class Node
	{
	public:
		T data;
		Node* left;
		Node* right;

		Node(T data = T(), Node* left = nullptr, Node* right = nullptr)
		{
			this->data = data;
			this->left = left; 
			this->right = right;
		}
	};

	Node* root;
	void show_prefix(Node*& node);
	void show_postfix(Node*& node);
	void add(T data, Node*& node);
	void clear(Node* node);
	void print(Node*& node, int tabs);
	int find_length(Node* node,T data);
public:
	BinaryTree();
	~BinaryTree();
	void add(T data);
	void clear();
	void show_prefix();
	void show_postfix();
	void print();
	int find_length(T data);
	
};

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	clear(root);
}

template<class T>
inline void BinaryTree<T>::add(T data)
{
	add(data, root);
}

template<class T>
inline void BinaryTree<T>::clear()
{
	clear(root);
}

template<class T>
inline void BinaryTree<T>::add(T data, Node*& node) {
	if (node == nullptr)
	{
		node = new Node(data);
	}
	else {
		if (node->data > data) {
			add(data, node->left);
		}
		else {
			add(data, node->right);
		}
	}
}


template<class T>
inline void BinaryTree<T>::show_prefix()
{
	show_prefix(root);
}

template<class T>
inline void BinaryTree<T>::show_postfix()
{
	show_postfix(root);
}

template<class T>
inline void BinaryTree<T>::print()
{
	int tabs = 0;
	print(root, tabs);
}

template<class T>
inline void BinaryTree<T>::print(Node*& node, int tabs)
{
	if (node == nullptr) return;  
	tabs += 5;  
	print(node->left, tabs); 
	for (int i = 0; i < tabs; i++) cout << " "; 
	cout << node->data << endl; 
	print(node->right, tabs); 
	tabs -= 5;  
	return;
}

template<class T>
inline void BinaryTree<T>::clear(Node* node)
{
	if (node) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

template<class T>
inline void BinaryTree<T>::show_prefix(Node*& node)
{
	if (node) {
		cout << node->data << " "; 
		if (node->left) {
			show_prefix(node->left); 
		}
		if (node->right) {
			show_prefix(node->right);   
		}           
	}
	else {
		cout << endl << "Empty tree!";
	}
}

template<class T>
inline void BinaryTree<T>::show_postfix(Node*& node)
{
	if (node) {
		if (node->left) {
			show_postfix(node->left);
		}
		if (node->right) {
			show_postfix(node->right);
		}
		cout << node->data << " ";
	}
	else {
		cout << endl << "Empty tree!";
	}
}

template<class T>
inline int BinaryTree<T>::find_length(T data)
{
	return find_length(root, data);
}

template<typename T>
inline int BinaryTree<T>::find_length(Node* node, T data)
{
	Node* work;
	int result = -1;
	work = node;
	if (work != nullptr)
	{
		if (work->data == data)
		{
			return 0;
		}
		int left = find_length(work->left, data);
		int right = find_length(work->right, data);
		if (left > right)
		{
			result = left;
		}
		else
		{
			result = right;
		}
	}
	if (result == -1)
	{
		return -1;
	}
	else
	{
		return result + 1;
	}
}