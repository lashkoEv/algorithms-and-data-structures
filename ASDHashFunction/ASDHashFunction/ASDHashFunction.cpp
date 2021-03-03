#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;

void transit();
int correct_input();
int menu();
void division();
void multiplication();
void string_key();

int correct_input()
{
    int number, flag = 0;
    while (true){
        flag = 0;
        cin >> number;
        if (!cin.good()){
            cin.clear();
            cin.get();
            if (flag == 0){
                cout << "Only numbers! ";
                flag++;
            }
        }
        else  return number;
    }
}

void transit() {
    while (true) {
        int key = menu();
        system("CLS"); 
        switch (key) {
        case 0: {
            division();
            break;
        }
        case 1: {
            multiplication();
            break;
        }
        case 2: {
            string_key();
            break;
        }
        }
        cout << endl;
        system("pause");
    }
}

int menu() {
    int code(0), key(0);
    do {
        system("CLS");
        setlocale(0, "");
        cout << endl << "                MAIN MENU";
        cout << endl << endl;
        if (key == 0) cout << endl << ">   1. Division method" << endl;
        else cout << endl << " 1. Division method" << endl;
        if (key == 1) cout << endl << ">   2. Multiplication method" << endl;
        else cout << endl << " 2. Multiplication method" << endl;
        if (key == 2) cout << endl << ">   3. String Key Method" << endl;
        else cout << endl << " 3. String Key Method" << endl;
        cout << endl << "   Press ESC to stop working with the program";
        code = _getch();
        if (code == 80) key++;
        if (code == 72) key--;
        if (key > 2) key = 0;
        if (key < 0) key = 2;
    } while (code != 13 && code != 27);
    if (code == 27) exit(0);
    return key;
}

//----------------------------------------------------------------------------------------------------

template <class T>
int hash_function_division(T data, int size = 10) {
    // instanceof проверка
    return data % size;
}

void division() {
    cout << "Enter size: ";
    int size, number, ans;
    //size = 10;
    size = correct_input(); 
    do {
        cout << "Enter number: ";
        number = correct_input();
        cout << "Hashcode for " << number << " is " << hash_function_division<int>(number, size);
        cout << endl << "Do you want to continue? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

//----------------------------------------------------------------------------------------------------

template <class T>
int hash_function_multiplication(T data, int size = 10) {
    // instanceof проверка
    double A = (pow(5, 0.5) - 1) / 2;
    return size * fmod(data * A, 1);
   // return size*((int)(A * data) % 1);
}

void multiplication() {
    cout << "Enter size: ";
    int size, number, ans;
    //size = 13;
    size = correct_input(); 
    do {
        cout << "Enter number: ";
        number = correct_input();
        cout << "Hashcode for " << number << " is " << hash_function_multiplication<int>(number, size);
        cout << endl << "Do you want to continue? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

//----------------------------------------------------------------------------------------------------

template <class T>
int hash_function_string_key(T data, int size = 10, int a = 2) {
    // instanceof проверка
    int res = 0;
    vector<char> cstr(data.c_str(), data.c_str() + data.size() + 1);
    for (int i = 0; i < cstr.size() - 1; i++)
    {
      //  cout << i << "  " << static_cast<int>(cstr[i]);// << endl;
      //  cout <<"  "<< i << "  " << pow(a,i) << endl;
        res += static_cast<int>(cstr[i]) * pow(a, i);
    }

    /*cout << res % size << endl;
    cout << fmod(res, size) << endl;*/
    //return res % size;
    return fmod(res, size);
}

void string_key() {
    int size, ans, a;
    string str;
    cout << "Enter size: ";
 //   size = 10;
    size = correct_input(); 
    cout << "Enter variable a: ";
 //   a = 2;
    a = correct_input();
    do {
        cout << "Enter string: ";
        cin >> str;
        cout << "Hashcode for " << str << " is " << hash_function_string_key<string>(str, size, a);
        cout << endl << "Do you want to continue? (Press 1): ";
        cin >> ans;
    } while (ans == 1);
}

//----------------------------------------------------------------------------------------------------

int main()
{
    transit();
    return 0;
}

