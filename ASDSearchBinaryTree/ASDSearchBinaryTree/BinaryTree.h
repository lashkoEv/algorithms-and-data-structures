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
	int find_length(Node* node, T data);
	bool find(Node* node, T data, bool& f);
	void find_parent(int data, Node*& current, Node*& parent);

public:
	BinaryTree();
	~BinaryTree();
	void add(T data);
	void remove(T data);
	void clear();
	void show_prefix();
	void show_postfix();
	void print();
	int find_length(T data);
	bool find(int data);

private:
	Node* remove(int data, Node*& node)
	{
		Node* tmp;
		if (node == nullptr) {
			return nullptr;
		}
		else {
			if (data < node->data) {
				node->left = remove(data, node->left);
			}
			else {
				if (data > node->data) {
					node->right = remove(data, node->right);
				}
				else {
					if (node->left && node->right) {
						tmp = find_min(node->right);
						node->data = tmp->data;
						node->right = remove(node->data, node->right);
					}
					else {
						tmp = node;
						if (node->left == nullptr)
							node = node->right;
						else {
							if (node->right == nullptr) {
								node = node->left;
							}
						}
						delete tmp;
					}
				}
			}
		}
		return node;
	}

	Node* find_min(Node* node)
	{
		if (node == nullptr) {
			return nullptr;
		}
		else {
			if (node->left == nullptr) {
				return node;
			}
			else {
				return find_min(node->left);
			}
		}
	}
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
	root = nullptr;
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
	if (work != nullptr) {
		if (work->data == data) {
			return 0;
		}
		int left = find_length(work->left, data);
		int right = find_length(work->right, data);
		if (left > right) {
			result = left;
		}
		else {
			result = right;
		}
	}
	if (result == -1) {
		return -1;
	}
	else {
		return result + 1;
	}
}

template<class T>
inline bool BinaryTree<T>::find(int data)
{
	bool f = false;
	return find(root, data, f);
}

template<class T>
inline bool BinaryTree<T>::find(Node* node, T data, bool& f)
{
	if (node) {
		cout << node->data << " ";
		if (node->data == data) {
			f = true;
			return f;
		}
		else {
			if (data < node->data) {
				find(node->left, data, f);
			}else {
				find(node->right, data, f);
			}
		}
	}
	return f;
}

template<class T>
inline void BinaryTree<T>::find_parent(int data, Node*& current, Node*& parent)
{
	current = root;
	while (current != nullptr)
	{
		if (data < current->data){
			parent = current;
			current = current->left;
		}
		else if (data > current->data){
			parent = current;
			current = current->right;
		}else{
			break;
		}
	}
	return;
}


template<class T>
inline void BinaryTree<T>::remove(T data)
{
	remove(data, root);
	//Node* tmpCurrent = nullptr, * tmpParent = nullptr;
	//find_parent(data, tmpCurrent, tmpParent);

	//if (tmpCurrent == nullptr)
	//{
	//	return;
	//}
	////cout << "cur " << tmpCurrent->data << endl;
	////if (tmpParent != nullptr) cout << "par " << tmpParent->data;
	////// Если лист дерева
	////if (tmpCurrent->left == nullptr && tmpCurrent->right == nullptr && tmpParent != nullptr) {
	////	Node* tmp = tmpCurrent;
	////	delete tmp;
	////}

	//// Если нет детей справа, заменяет левый ребенок
	//if (tmpCurrent->right == nullptr)
	//{
	//	if (tmpParent == nullptr)
	//	{
	//		Node* tmp = root;
	//		root = tmpCurrent->left;
	//		delete tmp;
	//	}
	//	else
	//	{
	//		if (tmpCurrent->data < tmpParent->data)
	//		{
	//			// Если значение родителя больше текущего,
	//			// левый ребенок текущего узла становится левым ребенком родителя
	//			Node* tmp = tmpParent->left;
	//			tmpParent->left = tmpCurrent->left;
	//			delete tmp;
	//		}
	//		else if (tmpCurrent->data > tmpParent->data) {
	//			// Если значение родителя меньше текущего, 
	//			// левый ребенок текущего узла становится правым ребенком родителя 
	//			Node* tmp = tmpParent->right;
	//			tmpParent->right = tmpCurrent->left;
	//			delete tmp;
	//		}
	//	}
	//}

	//// Если у правого ребенка нет детей слева 
	//// то он занимает место удаляемого узла 
	//else if (tmpCurrent->right->left == nullptr)
	//{
	//	tmpCurrent->right->left = tmpCurrent->left;
	//	if (tmpParent == nullptr) {
	//		Node* tmp = root;
	//		root = tmpCurrent->left;
	//		delete tmp;
	//	}
	//	else {
	//		if (tmpCurrent->data < tmpParent->data)
	//		{
	//			// Если значение родителя больше текущего,
	//			// правый ребенок текущего узла становится левым ребенком родителя
	//			Node* tmp = tmpParent->left;
	//			tmpParent->left = tmpCurrent->right;
	//			delete tmp;
	//		}
	//		else if (tmpCurrent->data > tmpParent->data) {
	//			// Если значение родителя меньше текущего, 
	//			// правый ребенок текущего узла становится правым ребенком родителя
	//			Node* tmp = tmpParent->right;
	//			tmpParent->right = tmpCurrent->right;
	//			delete tmp;
	//		}
	//	}
	//}

	//// Если у правого ребенка есть дети слева, крайний левый ребенок 
	//// из правого поддерева заменяет удаляемый узел
	//else {
	//	// Крайний левый узел
	//	Node* farLeft = tmpCurrent->right->left;
	//	Node* farLeftParent = tmpCurrent->right;
	//	while (farLeft->left != nullptr)
	//	{
	//		farLeftParent = farLeft;
	//		farLeft = farLeft->left;
	//	}
	//	// Левое поддерево родителя становится правым поддеревом крайнего левого узла
	//	// Левый и правый ребенок текущего узла становится левым и правым ребенком крайнего левого
	//	farLeftParent->left = farLeft->right;
	//	farLeft->left = tmpCurrent->left;
	//	farLeft->right = tmpCurrent->right;

	//	if (tmpParent == nullptr) {
	//		Node* tmp = root;
	//		root = farLeft;
	//		delete tmp;
	//	}
	//	else {
	//		if (tmpCurrent->data < tmpParent->data)
	//		{
	//			// Если значение родителя больше текущего,
	//			// крайний левый узел становится левым ребенком родителя
	//			Node* tmp = tmpParent->left;
	//			tmpParent->left = farLeft;
	//			delete tmp;
	//		}
	//		else if (tmpCurrent->data > tmpParent->data)
	//		{
	//			// Если значение родителя меньше текущего,
	//			// крайний левый узел становится правым ребенком родителя
	//			Node* tmp = tmpParent->right;
	//			tmpParent->right = farLeft;
	//			delete tmp;
	//		}
	//	}
	//}


}


