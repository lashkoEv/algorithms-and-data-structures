#pragma once
#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
	class Node
	{
	public:
		T data;
		Node* next;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node* head;

public:
	Stack();
	Stack(int data);
	~Stack();
	Stack(Stack<T>& stack);
	void push(T data);
	T pop();
	void clear();
	int get_size();
	T& operator[](int index);
	Stack<T>& operator= (const Stack<T>& stack);
	void show();
	void turn_over();
	bool belongs(T data);
	void change();
};

template<class T>
Stack<T>::Stack()
{
	this->head = nullptr;
	this->size = 0;
}

template<class T>
Stack<T>::Stack(int data)
{
	this->head = nullptr;
	this->size = 0;
	push(data);
}

template<class T>
Stack<T>::Stack(Stack<T>& stack)
{
	this->head = nullptr;
	this->size = 0;
	for (int i = stack.size - 1; i >= 0; i--) {
		push(stack[i]);
	}
}

template<class T>
Stack<T>::~Stack()
{
	clear();
}

template<class T>
void Stack<T>::push(T data)
{
	head = new Node(data, head);
	size++;
}

template<class T>
T Stack<T>::pop()
{
	if (head == nullptr) {
		throw "Stack empty!";
	}
	Node* tmp = this->head;
	int data = tmp->data;
	head = head->next;
	delete tmp;
	size--;
	return data;
}

template<class T>
void Stack<T>::clear()
{
	while (head != nullptr) {
		pop();
	}
}

template<class T>
T& Stack<T>::operator[](const int index)
{
	if (head == nullptr) {
		throw "Stack empty!";
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
Stack<T>& Stack<T>::operator= (const Stack<T>& stack)
{
	clear();
	for (int i = stack.size - 1; i >= 0; i--) {
		push(stack[i]);
	}
	return *this;
}

template<class T>
int Stack<T>::get_size()
{
	return size;
}

template<class T>
void Stack<T>::show()
{
	Node* tmp = this->head;
	cout << endl << "Stack: ";
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl << "Size: " << size << endl;
}

template<class T>
void Stack<T>::turn_over()
{
	Stack<T> stack;
	int tmpSize = size;
	for (int i = 0; i < tmpSize; i++)
	{
		stack.push(pop());
	}
	for (int i = tmpSize - 1; i >= 0; i--)
	{
		push(stack[i]);
	}
}

template<class T>
bool Stack<T>::belongs(T data)
{
	Node* tmp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (tmp->data == data) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

template<class T>
void Stack<T>::change()
{
	T first = head->data;
	Node* tmp = this->head;
	for (int i = 0; i < size - 1; i++)
	{
		tmp = tmp->next;
	}
	head->data = tmp->data;
	tmp->data = first;
}
