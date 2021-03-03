#pragma once

#include <iostream>
using namespace std;

template<class T>
class Queue
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
	Queue();
	Queue(int data);
	~Queue();
	Queue(Queue<T>& list);
	void push(T data);
	T pop();
	void clear();
	int get_size();
	T& operator[](int index);
	Queue<T>& operator= (const Queue<T>& stack);
	void show();
	void turn_over();
	bool belongs(T data);
	void change();
};

template<class T>
Queue<T>::Queue()
{
	this->head = nullptr;
	this->size = 0;
}

template<class T>
Queue<T>::Queue(int data)
{
	this->head = nullptr;
	this->size = 0;
	push(data);
}

template<class T>
Queue<T>::Queue(Queue<T>& queue)
{
	this->head = nullptr;
	this->size = 0;
	for (int i = queue.size - 1; i >= 0; i--) {
		push(queue[i]);
	}
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
void Queue<T>::push(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* tmp = this->head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data);

	}
	size++;
}

template<class T>
T Queue<T>::pop()
{
	if (head == nullptr) {
		throw "Queue empty!";
	}
	Node* tmp = this->head;
	int data = tmp->data;
	head = head->next;
	delete tmp;
	size--;
	return data;
}

template<class T>
void Queue<T>::clear()
{
	while (head != nullptr) {
		pop();
	}
}

template<class T>
T& Queue<T>::operator[](const int index)
{
	if (head == nullptr) {
		throw "Queue empty!";
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
Queue<T>& Queue<T>::operator= (const Queue<T>& queue)
{
	clear();
	for (int i = queue.size - 1; i >= 0; i--) {
		push(queue[i]);
	}
	return *this;
}

template<class T>
int Queue<T>::get_size()
{
	return size;
}

template<class T>
void Queue<T>::show()
{
	Node* tmp = this->head;
	cout << endl << "Queue: ";
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl << "Size: " << size << endl;
}

template<class T>
void Queue<T>::turn_over()
{
	Queue<T> queue;
	int tmpSize = size;
	for (int i = 0; i < tmpSize; i++)
	{
		queue.push(pop());
	}
	for (int i = tmpSize - 1; i >= 0; i--)
	{
		push(queue[i]);
	}
}

template<class T>
bool Queue<T>::belongs(T data)
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
void Queue<T>::change()
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
