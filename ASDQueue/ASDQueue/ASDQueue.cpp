#include <iostream>
#include "Queue.cpp"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter_queue(Queue<int>& queue);
void show_queue(Queue<int>& queue);
void transit(Queue<int>& queue);


int correct_input()
{
    cout << "Enter number: ";
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


void enter_queue(Queue<int>& queue) {
    system("CLS");
    cin.clear();
    cout << "Enter a queue: " << endl;
    int ans;
    do {
        int tmp = correct_input();
        queue.push(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}


void show_queue(Queue<int>& queue) {
    system("CLS");
    int tmp = queue.get_size();
    if (tmp == 0) {
        cout << "Queue empty!";
    }
    else {
        cout << "Queue: ";
        for (int i = 0; i < tmp; i++) {
            try {
                cout << queue.pop() << " ";
            }
            catch (const char*) {
                cout << endl << "Queue empty!";
            }
        }
    }
    cout << endl;
    system("pause");
}


void transit(Queue<int>& queue) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            queue.clear();
            cout << "Enter number: ";
            cin.clear();
            enter_queue(queue);
            break;
        }
        case 1: {
            show_queue(queue);
            break;
        }
        case 2: {
            system("CLS");
            queue.change();
            queue.show();
            system("pause");
            break;
        }
        case 3: {
            system("CLS");
            queue.turn_over();
            queue.show();
            system("pause");
            break;
        }
        case 4: {
            system("CLS");
            int num = correct_input();
            if (queue.belongs(num)) {
                cout << endl << "This item is on the queue!";
            }
            else {
                cout << endl << "This item is not on the queue!";
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
        if (key == 0) cout << endl << ">   1. Create queue";
        else cout << endl << " 1. Create queue";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show queue";
        else cout << endl << " 2. Show queue";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Change first and last";
        else cout << endl << " 3. Change first and last";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Turn over queue";
        else cout << endl << " 4. Turn over queue";
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
    Queue<int> queue;
    transit(queue);
    return 0;
}
