#include <iostream>
#include "Graph.h"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter(Graph& g);
void print(Graph& g);
void remove(Graph& g);
void breadth(Graph& g);
void depth(Graph& g);

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

void enter(Graph& g) {
    system("CLS");
    int ans;
    do {
        cout << "Enter from: ";
        int from = correct_input();
        cout << "Enter to: ";
        int to = correct_input();
        g.add(from, to);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

void print(Graph& g) {
    system("CLS");
    g.print();
    cout << endl;
    g.print_matrix();
    system("pause");
}

void remove(Graph& g) {
    system("CLS");
    cout << "Enter from: ";
    int from = correct_input();
    cout << "Enter to: ";
    int to = correct_input();
    g.remove(from, to);
    system("pause");
}

void breadth(Graph& g)
{
    system("CLS");
    cout << "Enter from: ";
    int from = correct_input();
    g.breadth_traversal(from);
    system("pause");
}

void depth(Graph& g)
{
    system("CLS");
    cout << "Enter from: ";
    int from = correct_input();
    g.depth_traversal(from);
    system("pause");
}
void transit(Graph& g) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter(g);
            break;
        }
        case 1: {
            print(g);
            break;
        }
        case 2: {
            remove(g);
            break;
        }
        case 3: {
            breadth(g);
            break;
        }
        case 4: {
            depth(g);
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
        if (key == 0) cout << endl << ">   1. Add way ";
        else cout << endl << " 1. Add way";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show graph";
        else cout << endl << " 2. Show graph";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Delete way";
        else cout << endl << " 3. Delete way";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Breadth traversal";
        else cout << endl << " 4. Breadth traversal";
        cout << endl;
        if (key == 4) cout << endl << ">   5. Depth traversal";
        else cout << endl << " 5. Depth traversal";
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
    cout << "Enter number of vertices: ";
    int number = correct_input();
    Graph g(number);
    transit(g);
    return 0;
}