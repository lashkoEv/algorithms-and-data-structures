#include <iostream>
#include "BinaryHeap.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter(BinaryHeap& b);
void print(BinaryHeap& b);
void remove(BinaryHeap& b);

int correct_input()
{
    cin.clear();
    int number, flag = 0;
    while (true)
    {
        flag = 0;
        cin >> number;
        if (!cin.good())
        {
            cin.clear();
            cin.get();
            if (flag == 0)
            {
                cout << "Enter number: ";
                flag++;
            }
        }
        else  return number;
    }
}

void enter(BinaryHeap& b) {
    system("CLS");
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        b.insert(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

void print(BinaryHeap& b) {
    system("CLS");
    b.print();
    system("pause");
}

void remove(BinaryHeap& b) {
    system("CLS");
    b.return_max();
    system("pause");
}

int* heap_sort_by_asc(int arr[], int count)
{
    BinaryHeap b;
    for (int i = 0; i < count; i++)
    {
        b.insert(arr[i]);
    }
    for (int i = count - 1; i >= 0; i--)
    {
        arr[i] = b.return_max();
        b.heapify(0);
    }
    return arr;
}

int* heap_sort_by_desc(int arr[], int count)
{
    BinaryHeap b;
    for (int i = 0; i < count; i++)
    {
        b.insert(arr[i]);
    }
    for (int i = 0; i < count; i++)
    {
        arr[i] = b.return_max();
        b.heapify(0);
    }
    return arr;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void sort_asc() {
    system("CLS");
    cout << "Enter array size: ";
    int size = correct_input();
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        arr[i] = correct_input();
    }
    cout << "Array before sorting: ";
    print_array(arr, size);
    heap_sort_by_asc(arr, size);
    cout << "Array after sorting: ";
    print_array(arr, size);
    system("pause");
}

void sort_desc() {
    system("CLS");
    cout << "Enter array size: ";
    int size = correct_input();
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        arr[i] = correct_input();
    }
    cout << "Array before sorting: ";
    print_array(arr, size);
    heap_sort_by_desc(arr, size);
    cout << "Array after sorting: ";
    print_array(arr, size);
    system("pause");
}

void transit(BinaryHeap& b) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter(b);
            break;
        }
        case 1: {
            print(b);
            break;
        }
        case 2: {
            remove(b);
            break;
        }
        case 3: {
            sort_asc();
            break;
        }
        case 4: {
            sort_desc();
            break;
        }
        }
    }
}


int menu() {
    int code(0), key(0);
    do {
        system("CLS");
        setlocale(0, "");
        cout << endl << "                MAIN MENU";
        cout << endl << endl;
        if (key == 0) cout << endl << ">   1. Add data ";
        else cout << endl << " 1. Add data";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show ";
        else cout << endl << " 2. Show ";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Delete max";
        else cout << endl << " 3. Delete max";
        cout << endl;
        if (key == 3) cout << endl << ">   4. ASC Sort";
        else cout << endl << " 4. ASC Sort";
        cout << endl;
        if (key == 4) cout << endl << ">   4. DESC Sort";
        else cout << endl << " 4. DESC Sort";
        cout << endl;
        cout << endl << "   Press ESC to stop working with the program";
        code = _getch();
        if (code == 80) key++;
        if (code == 72) key--;
        if (key > 4) key = 0;
        if (key < 0) key = 4;
    } while (code != 13 && code != 27);
    if (code == 27) exit(0);
    return key;
}

int main()
{
    BinaryHeap b;
    transit(b);
    return 0;
}