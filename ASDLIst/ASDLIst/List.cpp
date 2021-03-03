#include "List.h"
#include <iostream>
using namespace std;


template<class T>
List<T>::List()
{
	head = nullptr;
	size = 0;
}

template<class T>
List<T>::~List()
{
	clear();
}
template<class T>
List<T>::List(List<T>& list)
{
	this->head = nullptr;
	this->size = 0;
	for (int i = list.size - 1; i >= 0; i--) {
		add_first(list[i]);
	}
}

template<class T>
void List<T>::move(int from, int to)
{
	if (from >= 0 && from < size && to >= 0 && to < size) {
		T data;
		Node* tmpFrom = this->head; 
		for (int i = 0; i < from; i++) {
			tmpFrom = tmpFrom->next;
		}
		Node* tmpTo = this->head;
		for (int i = 0; i < to; i++) {
			tmpTo = tmpTo->next;
		}
		data = tmpFrom->data;
		tmpFrom->data = tmpTo->data;
		tmpTo->data = data;
	}
}

template<class T>
void List<T>::add_first(T data)
{
	head = new Node(data, head);
	size++;
}

template<class T>
void List<T>::add_last(T data)
{

	if (head == nullptr)
	{
		add_first(data);
	}
	else
	{
		add_index(data, size);
	}
}

template<class T>
void List<T>::add_index(T data, int index)
{
	if (index == 0 || head == nullptr){ add_first(data);}
	else
	{
		if (index <= size) {
			Node* tmp = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				tmp = tmp->next;
			}
			Node* new_node = new Node(data, tmp->next);
			tmp->next = new_node;
			size++;
		}
	}
}

template<class T>
void List<T>::merge(List<T> list)
{
	for (int i = 0; i < list.size; i++)
	{
		add_last(list[i]);
	}
}

template<class T>
void List<T>::delete_index(int index)
{
	if (head != nullptr) {
		if (index == 0)
		{
			delete_first();
		}
		else
		{
			Node* tmp = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				tmp = tmp->next;
			}
			Node* delete_node = tmp->next;
			tmp->next = delete_node->next;
			delete delete_node;
			size--;
		}
	}
}

template<class T>
void List<T>::delete_every(int number)
{
	if(number < size && number > 0)
	for (int i = number; i < size; i += number - 1) {
		delete_index(i);
	}
}


template<class T>
void List<T>::delete_first()
{
	if (head == nullptr) {
		throw "List empty!";
	}
	Node* tmp = this->head;
	int data = tmp->data;
	head = head->next;
	delete tmp;
	size--;
}

template<class T>
void List<T>::sort_asc()
{
	Node* left = head; 
	Node* right = head->next;
	Node* tmp = new Node;       
	while (left->next) {        
		while (right) {      
			if ((left->data) > (right->data)) {      
				tmp->data = left->data;       
				left->data = right->data;      
				right->data = tmp->data;    
			}
			right = right->next;    
		}
		left = left->next;           
		right = left->next;    
	}
}

template<class T>
void List<T>::sort_desc()
{
	Node* left = head;
	Node* right = head->next;
	Node* tmp = new Node;
	while (left->next) {
		while (right) {
			if ((left->data) < (right->data)) {
				tmp->data = left->data;
				left->data = right->data;
				right->data = tmp->data;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

template<class T>
void List<T>::clear()
{
	while (head != nullptr) {
		delete_first();
	}
}

template<class T>
inline int List<T>::get_size()
{
	return size;
}

template<class T>
T& List<T>::operator[](const int index)
{
	if (head == nullptr) {
		throw "List empty!";
	}
	Node* tmp = this->head;
	int tmpIndex = 0;
	while (tmp->next != nullptr)
	{
		if (tmpIndex == index)
		{
			return tmp->data;
		}
		else {
			tmp = tmp->next;
			tmpIndex++;
		}
	}
}

template<class T>
void List<T>::show()
{
	Node* tmp = this->head;
	cout << endl << "List: ";
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl << "Size: " << size << endl;
}

template<class T>
List<T> List<T>::common(List<T>& list)
{
	List<T> result;
	Node* tmp = this->head;
	Node* tmpList = list.head;
	while (tmp != nullptr)
	{
		tmpList = list.head;
		while (tmpList != nullptr)
		{
			if (tmp->data == tmpList->data) {
				result.add_last(tmp->data);
			}
			tmpList = tmpList->next;
		}
		tmp = tmp->next;
	}
	return result;
}

template<class T>
List<T> List<T>::copy()
{
	List<T> result;
	Node* tmp = this->head;
	for (int i = 0; i < size; i++)
	{
		result.add_last(tmp->data);
		tmp = tmp->next;
	}
	return result;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
	clear();
	this->head = nullptr;
	this->size = 0;
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		add_last(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}


