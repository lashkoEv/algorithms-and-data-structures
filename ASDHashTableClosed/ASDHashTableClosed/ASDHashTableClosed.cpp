#pragma once
#include <iostream>
#include "HashTable.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter(HashTable& ht);
void remove(HashTable& ht);
void find(HashTable& ht);
void show(HashTable& ht);
void transit(HashTable& ht);


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


void enter(HashTable& ht) {
    system("CLS");
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        ht.add(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}


void show(HashTable& ht) {
    system("CLS");
    ht.show();
    system("pause");
}


void remove(HashTable& ht) {
    system("CLS");
    cout << "Enter key: ";
    int key = correct_input();
    ht.remove(key);
    system("pause");
}

void find(HashTable& ht)
{
    system("CLS");
    cout << "Enter key: ";
    int key = correct_input();
    if (ht.is_find(key)) {
        cout << "Finded: " << ht.find(key) << endl;
    }
    else {
        cout << "Nothing found!" << endl;
    }
    system("pause");
}

void transit(HashTable& ht) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter(ht);
            break;
        }
        case 1: {
            show(ht);
            break;
        }
        case 2: {
            remove(ht);
            break;
        }
        case 3: {
            find(ht);
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
        if (key == 0) cout << endl << ">   1. Add data to hash table";
        else cout << endl << " 1. Add data to hash table";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show hash table --- debug";
        else cout << endl << " 2. Show hash table --- debug";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Remove by the key";
        else cout << endl << " 3. Remove by the key";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Find by the key";
        else cout << endl << " 4. Find by the key";
        cout << endl;
        cout << endl << "   Press ESC to stop working with the program";
        code = _getch();
        if (code == 80) key++;
        if (code == 72) key--;
        if (key > 3) key = 0;
        if (key < 0) key = 3;
    } while (code != 13 && code != 27);
    if (code == 27) exit(0);
    return key;
}

int main()
{
    HashTable ht;
    transit(ht);
    return 0;
}
