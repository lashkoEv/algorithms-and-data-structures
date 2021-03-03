#pragma once
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

class Graph
{
	int size;
	bool** nodes;

public:
	Graph(int n) {
		size = n;
		nodes = new bool* [size];
		for (int i = 0; i < size; i++)
		{
			nodes[i] = new bool[size];
			for (int j = 0; j < size; j++)
			{
				nodes[i][j] = false;
			}
		}
	}

	~Graph() {
		for (int i = 0; i < size; i++)
		{
			delete nodes[i];
		}
		delete[] nodes;
		size = 0;
	}

	int get_size() {
		return size;
	}

	void add(int from, int to) {
		if (from < 0 || from >= size || to < 0 || to >= size) {
			return;
		}
		nodes[from][to] = true;
		nodes[to][from] = true;
	}

	void remove(int from, int to) {
		if (from < 0 || from >= size || to < 0 || to >= size) {
			return;
		}
		nodes[from][to] = false;
		nodes[to][from] = false;
	}

	void print() {
		for (int i = 0; i < size; i++)
		{
			cout << i << " - ";
			for (int j = 0; j < size; j++) {
				if(nodes[i][j])
					cout << j << "; ";
			}
			cout << endl;
		}
	}

	void print_matrix() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) {
				cout << nodes[i][j] << "  ";
			}
			cout << endl;
		}
	}

	// ширина
	void breadth_traversal(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		cout << endl << "Breadth traversal: ";

		Queue<int> queue;
		int* visited = new int[size];
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}

		queue.push(index);	
		while (queue.get_size() != 0) 
		{ 
			int node = queue.pop();
			visited[node] = 2;  // отмечаем как посещенную
			for (int i = 0; i < size; i++) // проверяем  все смежные вершины
			{ 
				if (nodes[node][i] == true && visited[i] == 0)// если вершина смежная и не обнаружена
				{ 
					queue.push(i);
					visited[i] = 1;
				}
			}
			cout << node << "; ";
		}
	}

	// глубина
	void depth_traversal(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		cout << endl << "Depth traversal: ";

		Stack<int> stack;
		
		int* visited = new int[size]; // вершины графа
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}
		stack.push(index); 
		while (stack.get_size() != 0) 
		{ 
			int node = stack.pop(); 
			if (visited[node] == 2) continue;
			visited[node] = 2;
			for (int j = size - 1; j >= 0; j--)// проверяем все смежные вершины
			{ 
				if (nodes[node][j] == true && visited[j] != 2) // если вершина смежная и не обнаружена
				{ 
					stack.push(j); // добавляем ее в cтек
					visited[j] = 1; // отмечаем вершину как обнаруженную
				}
			}
			cout << node << "; "; // выводим номер вершины
		}
	}
};

