#pragma once

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

