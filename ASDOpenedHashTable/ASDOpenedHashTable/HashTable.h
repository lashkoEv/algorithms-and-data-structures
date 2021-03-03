#pragma once
#include "List.cpp"
class HashTable
{
	int size;
	List<int>* arr;
	int hash_function(int data);
public:
	HashTable(int size);
	HashTable();
	~HashTable();
	void add(int data);
	void remove(int key);
	bool is_find(int key);
	List<int> find(int key);
	void show();
};

