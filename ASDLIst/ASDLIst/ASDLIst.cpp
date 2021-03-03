#include <iostream>
#include "List.cpp"
#include <conio.h>
#include <iomanip>
using namespace std;

int menu();
int correct_input();
void enter_list(List<int>& list);
void show_list(List<int>& list);
void transit(List<int>& list);


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


void enter_list(List<int>& list) {
    system("CLS"); 
    list.clear();
    cout << "Enter a list: " << endl;
    int ans;
    do {
        cout << "Enter number: ";
        int tmp = correct_input();
        list.add_first(tmp);
        cout << "Do you want to add more? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}


void show_list(List<int>& list) {
    system("CLS");
    if (list.get_size() == 0) {
        cout << "List empty!" << endl;
    }
    else {
        list.show();
    }
    system("pause");
}

void move(List<int>& list) {
    system("CLS");
    cout << "From: ";
    int from = correct_input();
    cout << "To: "; 
    int to = correct_input();
    cout << "Initial list: ";
    list.show(); 
    list.move(from, to);
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void copy(List<int>& list) {
    system("CLS");
    cout << "Initial list: ";
    list.show();
    List<int> newList;
    newList = list.copy();
    cout << "Copy list: ";
    newList.show();
    system("pause");
}

void merge(List<int>& list) {
    system("CLS");
    List<int> l;
    enter_list(l);
    cout << "Initial list: ";
    list.show();
    list.merge(l);
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void remove_by_index(List<int>& list) {
    system("CLS");
    cout << "Enter index: ";
    int index = correct_input();
    cout << "Initial list: ";
    list.show();
    list.delete_index(index);
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void insert(List<int>& list) {
    system("CLS");
    cout << "Enter data: ";
    int data = correct_input();
    cout << "Enter index: ";
    int index = correct_input();
    cout << "Initial list: ";
    list.show();
    list.add_index(data, index);
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void sort_asc(List<int>& list) {
    system("CLS");
    cout << "Initial list: ";
    list.show();
    list.sort_asc();
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void sort_desc(List<int>& list) {
    system("CLS");
    cout << "Initial list: ";
    list.show();
    list.sort_desc();
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void common(List<int>& list) {
    system("CLS");
    List<int> l;
    enter_list(l);
    cout << "First initial list: ";
    list.show(); 
    cout << "Second initial list: ";
    l.show();
    List<int> res;
    res = list.common(l);
    cout << "Resulting list: ";
    res.show();
    system("pause");
}

void remove_every(List<int>& list) {
    system("CLS");
    cout << "Enter index: ";
    int index = correct_input();
    cout << "Initial list: ";
    list.show();
    list.delete_every(index);
    cout << "Resulting list: ";
    list.show();
    system("pause");
}

void clear(List<int>& list) {
    system("CLS");
    list.clear();
    cout << "List clear!" << endl;
    system("pause");
}

void transit(List<int>& list) {
    while (true) {
        int key = menu();
        switch (key) {
        case 0: {
            enter_list(list);
            break;
        }
        case 1: {
            show_list(list);
            break;
        }
        case 2: {
            move(list);
            break;
        }
        case 3: {
            copy(list);
            break;
        }
        case 4: {
            merge(list);
            break;
        }
        case 5: {
            remove_by_index(list);
            break;
        }
        case 6: {
            insert(list);
            break;
        }
        case 7: {
            common(list);
            break;
        }
        case 8: {
            sort_asc(list);
            break;
        }
        case 9: {
            sort_desc(list);
            break;
        }
        case 10: {
            remove_every(list);
            break;
        }
        case 11: {
            clear(list);
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
        if (key == 0) cout << endl << ">   1. Create a list by adding to the beginning";
        else cout << endl << " 1. Create a list by adding to the beginning";
        cout << endl;
        if (key == 1) cout << endl << ">   2. Show list";
        else cout << endl << " 2. Show list";
        cout << endl;
        if (key == 2) cout << endl << ">   3. Move element";
        else cout << endl << " 3. Move element";
        cout << endl;
        if (key == 3) cout << endl << ">   4. Create a copy of the list";
        else cout << endl << " 4. Create a copy of the list";
        cout << endl;
        if (key == 4) cout << endl << ">   5. Merge lists";
        else cout << endl << " 5. Merge lists";
        cout << endl;
        if (key == 5) cout << endl << ">   6. Remove list item by index";
        else cout << endl << " 6. Remove list item by index";
        cout << endl;
        if (key == 6) cout << endl << ">   7. Insert after element by index";
        else cout << endl << " 7. Insert after element by index";
        cout << endl;
        if (key == 7) cout << endl << ">   8. Create a list of common items";
        else cout << endl << " 8. Create a list of common items";
        cout << endl;
        if (key == 8) cout << endl << ">   9. Sort the list in ascending order of elements";
        else cout << endl << " 9. Sort the list in ascending order of elements";
        cout << endl;
        if (key == 9) cout << endl << ">   10. Sort the list in descending order of items";
        else cout << endl << " 10. Sort the list in descending order of items";
        cout << endl;
        if (key == 10) cout << endl << ">   11. Remove every n-th element";
        else cout << endl << " 11. Remove every n-th element";
        cout << endl;
        if (key == 11) cout << endl << ">   12. Clear list";
        else cout << endl << " 12. Clear list";
        cout << endl;
        cout << endl << "   Press ESC to stop working with the program";
        code = _getch();
        if (code == 80) key++;
        if (code == 72) key--;
        if (key > 11) key = 0;
        if (key < 0) key = 11;
    } while (code != 13 && code != 27);
    if (code == 27) exit(0);
    return key;
}


int main()
{
    List<int> list;
    transit(list);
    return 0;
}
