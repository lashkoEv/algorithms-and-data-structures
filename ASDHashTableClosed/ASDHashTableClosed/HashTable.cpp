#include "HashTable.h"

int HashTable::hash_function(int data)
{
    return data % size;
}

HashTable::HashTable()
{
    size = 3;
    arr = new Node[size];
}

HashTable::~HashTable()
{
    delete[] arr;
}

void HashTable::add(int data)
{
    int key;
    key = hash_function(data);
    while (!arr[key].deleted && arr[key].data != data) {
        key = (key + 1) % size; 
    }
    if (arr[key].deleted) {
        arr[key].deleted = false;
    }
    arr[key].data = data;
    arr[key].key = data;
    if (is_restructure()) { restructure(); }
}

void HashTable::remove(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i].key) {
            arr[i].deleted = true;
            arr[i].data = 0;
            arr[i].key = 0;
        }
    }
}

bool HashTable::is_find(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i].key && !arr[i].deleted) {
            return true;
        }
    }
    return false;
}

void HashTable::show()
{
    cout << endl << "Idx\tDel\tKey\tData" << endl;
    for (int i = 0; i < size; i++)
    {
       cout << i << "\t" << arr[i].deleted << "\t" << arr[i].key << "\t" << arr[i].data << endl;
    }
}

int HashTable::find(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i].key && !arr[i].deleted) {
            return arr[i].data;
        }
    }
    return -1;
}

void HashTable::restructure()
{
    Node* old_arr = new Node[size];
    int old_size = size;
    for (int i = 0; i < old_size; i++)
    {
        if (arr[i].deleted == false) {
            old_arr[i].data = arr[i].data;
            old_arr[i].key = arr[i].key;
            old_arr[i].deleted = arr[i].deleted;
            cout << arr[i].data << " ";
        }
    }
    delete[] arr;
    size = size + 10;
    arr = new Node[size];
    for (int i = 0; i < old_size; i++)
    {
        add(old_arr[i].data);
    }
    delete[] old_arr;
    cout << endl << "--- debug Restructure!";
}

bool HashTable::is_restructure()
{
    double enough = size * 0.85;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!arr[i].deleted) {
            count++;
        }
    }
    if (count >= enough) {
        return true;
    }
    else {
        return false;
    }
}
