#pragma once
#include <iostream>
using namespace std;

constexpr auto ADD_SIZE = 15;

class BinaryHeap {
private:
    int* heap;
    int size;

public:
    BinaryHeap() {
        heap = new int[ADD_SIZE];
        size = 0;
    }

    ~BinaryHeap() {
        remove();
    }

    void remove() {
        delete[] heap;
        size = 0;
    }

    int parent(int current) {
        return (current - 1) / 2;
    }

    int left_�hild(int current) {
        return 2 * current + 1;
    }

    int right_�hild(int current) {
        return 2 * current + 2;
    }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    int return_max() {
        int max_item = heap[0];
        heap[0] = heap[size - 1];
        size = size - 1;
        heapify(0);
        return max_item;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void insert(int data) {
        if (size >= ADD_SIZE) {
            const int q = size;
            int* new_heap = new int[size + ADD_SIZE];
            for (int i = 0; i < size; i++) {
                new_heap[i] = heap[i];
            }
            delete[] heap;
            heap = new_heap;
            print();
        }
        heap[size] = data;
        size = size + 1;
        // �������� ����� ��� �������� ���������� �������� ����
        int index = size - 1;
        while (index != 0 && heap[parent(index)] < heap[index]) {
            swap(&heap[parent(index)], &heap[index]);
            index = parent(index);
        }
    }

    void heapify(int current) {
        int left = left_�hild(current);
        int right = right_�hild(current);

        int largest = current;
        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }
        // ������ ������� ����� ������� ���� �� ������� ����
        // � ��������� ���� �������, ���� ������� ���� �� ������ ������, ��� ������ � ����� ����
        if (largest != current) {
            int temp = heap[current];
            heap[current] = heap[largest];
            heap[largest] = temp;
            heapify(largest);
        }
    }

    int get_max() {
        return heap[0];
    }
};


