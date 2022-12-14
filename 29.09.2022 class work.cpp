#include <Windows.h>
#include <iostream>
#include <conio.h>

#include "Tree.h"
#include "Functions.h"
using namespace std;


static int a;
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    cout << a;

    Tree tree;

    bool exit = false;

    for (;;) {
        PrintMenu();

        int choice = _getch();

        switch (choice) {
        case '1':
            Insert(tree);
            break;

        case '2':
            Remove(tree);
            break;

        case '3':
            Print(tree);
            break;

        case '4':
            Search(tree);
            break;

        case '5':
            Edit(tree);
            break;

        case '6':
            SaveFile(tree);
            break;

        case '7':
            exit = true;
            break;
        }

        if (exit) {
            break;
        }
    }

    return 0;
}

