#pragma once
#include <iostream>
using namespace std;
class HashTable
{
	class Node
	{
	public:
		int data;
		int key;
		bool deleted;
		Node(int data = 0, int key = 0, bool deleted = true) : data(data), deleted(true), key(key) {}
	};

	Node* arr;
	int size;
	int hash_function(int data);
	void restructure();
	bool is_restructure();
public:
	HashTable();
	~HashTable();
	void add(int data);
	void remove(int key);
	bool is_find(int key);
	int find(int key);
	void show();
};

