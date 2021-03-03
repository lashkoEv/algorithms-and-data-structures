#include <iostream>
#include "BinaryTree.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter(BinaryTree<int>& b);
void prefix(BinaryTree<int>& b);
void show(BinaryTree<int>& b);
void postfix(BinaryTree<int>& b);
void find(BinaryTree<int>& b);
void remove(BinaryTree<int>& b);


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


void enter(BinaryTree<int>& b) {
    system("CLS");
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        b.add(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

void prefix(BinaryTree<int>& b)
{
    system("CLS");
    b.show_prefix();
    cout << endl;
    system("pause");
}


void show(BinaryTree<int>& b) {
    system("CLS");
    b.print();
    system("pause");
}

void postfix(BinaryTree<int>& b)
{
    system("CLS");
    b.show_postfix();
    cout << endl;
    system("pause");
}

void find(BinaryTree<int>& b)
{
    system("CLS");
    cout << "Enter number: ";
    int tmp = correct_input();
    if (b.find(tmp)) {
        cout << "Yes" << endl;
    }
    else {

        cout << "No" << endl;
    }
    cout << endl;
    system("pause");
}

void remove(BinaryTree<int>& b)
{
    system("CLS");
    cout << "Enter number: ";
    int tmp = correct_input();
    b.remove(tmp);
    cout << endl;
    system("pause");
}


void transit(BinaryTree<int>& b) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter(b);
            break;
        }
        case 1: {
            show(b);
            break;
        }
        case 2: {
            prefix(b);
            break;
        }
        case 3: {
            postfix(b);
            break;
        }
        case 4: {
            find(b);
            break;
        }
        case 5: {
            remove(b);
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
        if (key == 2) cout << endl << ">   3. Prefix";
        else cout << endl << " 3. Prefix";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Postfix";
        else cout << endl << " 4. Postfix";
        cout << endl;
        if (key == 4) cout << endl << ">   5. Find";
        else cout << endl << " 5. Find";
        cout << endl;
        if (key == 5) cout << endl << ">   6. Remove";
        else cout << endl << " 6. Remove";
        cout << endl;
        cout << endl << "   Press ESC to stop working with the program";
        code = _getch();
        if (code == 80) key++;
        if (code == 72) key--;
        if (key > 5) key = 0;
        if (key < 0) key = 5;
    } while (code != 13 && code != 27);
    if (code == 27) exit(0);
    return key;
}

int main()
{
    BinaryTree<int> b;
   /* b.add(10);
    b.add(20);
    b.add(30);
    b.add(15);
    b.add(5); 
    b.add(7); 
    b.add(8); 
    b.add(6); 
    b.add(3); 
    b.add(4); 
    b.add(1); */
    transit(b);
    return 0;
}
