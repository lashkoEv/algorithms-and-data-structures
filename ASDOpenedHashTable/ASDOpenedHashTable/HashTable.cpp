#pragma once
#include "HashTable.h"
#include "iostream"
using namespace std;

int HashTable::hash_function(int data)
{
	return data % size;
}

HashTable::HashTable(int size)
{
	if (size > 0) {
		this->size = size;
		arr = new List<int>[size];
	}
	else {
		throw "Incorrect size!";
	}
}

HashTable::HashTable()
{
	this->size = 3;
	arr = new List<int>[size];
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].clear();
	}
	delete[] arr;
}

void HashTable::add(int data)
{
	int key = hash_function(data);
	arr[key].add_last(data);
}

void HashTable::remove(int key)
{
	key = hash_function(key);
	if (!arr[key].is_empty()) {
		arr[key].clear();
		cout << "Successfully removed!" << endl;
	}
	else {
		cout << "No data to remove!" << endl;
	}
}

bool HashTable::is_find(int key)
{
	key = hash_function(key);
	if (!arr[key].is_empty()) {
		return true;
	}
	return false;
}

List<int> HashTable::find(int key)
{
	key = hash_function(key);
	if (!arr[key].is_empty()) {
		return arr[key];
	}
	List<int> l;
	return l;
}

void HashTable::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Index: " << i;
		arr[i].show(); 
		cout << endl;
	}
}
