#pragma once

template<class T>
class List
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
	List();
	~List();
	List(List<T>& list);
	List<T> copy();
	void add_first(T data);
	void add_last(T data);
	void add_index(T data, int index);
	void delete_index(int index);
	void delete_every(int number);
	void delete_first();
	void move(int from, int to);
	void merge(List<T> list);
	void sort_asc();
	void sort_desc();
	void clear();
	void show();
	int get_size();
	T& operator[](int index);
	List<T>& operator= (const List<T>& list);
	List<T> common(List<T>& list);
};
  
