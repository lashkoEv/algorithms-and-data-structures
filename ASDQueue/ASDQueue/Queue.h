#pragma once

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

