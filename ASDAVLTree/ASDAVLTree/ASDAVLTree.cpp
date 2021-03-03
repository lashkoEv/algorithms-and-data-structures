#include<iostream>
#include "AVLTree.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter(AVLTree<int>& t);
void show(AVLTree<int>& t);
void clear(AVLTree<int>& t);
void remove(AVLTree<int>& t);


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


void enter(AVLTree<int>& t) {
    system("CLS");
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        t.add(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

void show(AVLTree<int>& t) {
    system("CLS");
    t.print();
    system("pause");
}

void clear(AVLTree<int>& t) {
    system("CLS");
    t.clear();
    system("pause");
}

void remove(AVLTree<int>& t)
{
    system("CLS");
    cout << "Enter number: ";
    int tmp = correct_input();
    t.remove(tmp);
    cout << endl;
    system("pause");
}


void transit(AVLTree<int>& t) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter(t);
            break;
        }
        case 1: {
            show(t);
            break;
        }
        case 2: {
            clear(t);
            break;
        }
        case 3: {
            remove(t);
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
        if (key == 2) cout << endl << ">   3. Clear";
        else cout << endl << " 3. Clear";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Remove";
        else cout << endl << " 4. Remove";
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
    AVLTree<int> b;
    b.add(30);
    b.add(40);
    b.add(10);
    b.add(50);
    b.add(9);
    b.add(29);
 
    transit(b);
    return 0;
}