#include <iostream>
#include "Stack.cpp"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter_stack(Stack<int>& stack);
void show_stack(Stack<int>& stack);
void transit(Stack<int>& stack);


int correct_input()
{
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


void enter_stack(Stack<int>& stack) {
    system("CLS");
    cin.clear();
    cout << "Enter a stack: " << endl;
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        stack.push(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}


void show_stack(Stack<int>& stack) {
    system("CLS"); 
    int tmp = stack.get_size();
    if (tmp == 0) {
        cout << "Stack empty!";
    }
    else {
        cout << "Stack: ";
        for (int i = 0; i < tmp; i++) {
            try {
                cout << stack.pop() << " ";
            }
            catch (const char*) {
                cout << endl << "Stack empty!";
            }
        }
    }
    cout << endl;
    system("pause");
}


void transit(Stack<int>& stack) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            stack.clear(); 
            cout << "Enter number: "; 
            cin.clear();
            enter_stack(stack);
            break;
        }
        case 1: {
            show_stack(stack);
            break;
        }
        case 2: {
            system("CLS");
            stack.change();
            stack.show();
            system("pause");
            break;
        }
        case 3: {
            system("CLS");
            stack.turn_over();
            stack.show();
            system("pause");
            break;
        }
        case 4: {
            system("CLS");
            int num = correct_input();
            if (stack.belongs(num)) {
                cout << endl << "This item is on the stack!";
            }
            else {
                cout << endl << "This item is not on the stack!";
            }
            cout << endl;
            system("pause");
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
        if (key == 0) cout << endl << ">   1. Create stack";
        else cout << endl << " 1. Create stack";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show stack";
        else cout << endl << " 2. Show stack";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Change first and last";
        else cout << endl << " 3. Change first and last";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Turn over stack";
        else cout << endl << " 4. Turn over stack";
        cout << endl;
        if (key == 4) cout << endl << ">   5. Does the item belong?";
        else cout << endl << " 5. Does the item belong?";
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
    Stack<int> stack;
    transit(stack);
    return 0;
}
