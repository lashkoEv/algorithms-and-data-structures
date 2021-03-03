#pragma once
#include <iostream>
using namespace std;

constexpr auto ADD_SIZE = 15;

class PriorityQueue
{

//	class Node {
//		int priority;
//		int data;
//    public:
//		Node(int pr = 0, int dt = 0) {
//			priority = pr;
//			data = dt;
//		}
//	};
//
//	Node* heap;
//	int size;
//	
//public:
//
//    PriorityQueue() {
//        heap = new Node[ADD_SIZE];
//        size = 0;
//    }

    //void insert(int data) {
    //    if (size >= ADD_SIZE) {
    //        const int q = size;
    //        Node* new_heap = new Node[size + ADD_SIZE];
    //        for (int i = 0; i < size; i++) {
    //            new_heap[i] = heap[i];
    //        }
    //        delete[] heap;
    //        heap = new_heap;
    //        //print();
    //    }

    //    heap[size] = data;
    //    size = size + 1;

    //    // движение вверх для проверки соблюдения принципа кучи
    //    int index = size - 1;
    //    while (index != 0 && heap[parent(index)] < heap[index]) {
    //        swap(&heap[parent(index)], &heap[index]);
    //        index = parent(index);
    //    }
    //}
};

