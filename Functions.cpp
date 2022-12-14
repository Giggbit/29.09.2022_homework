#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu() {
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6. Save file\n7. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void Edit(Tree& tree) {
    system("cls");

    char buffer[15];
    cout << "Enter which word you want edit: ";
    cin >> buffer;
    Node* node = tree.Search(tree.GetRoot(), buffer);

    Node* temp = new Node;
    cout << endl << "Enter new english word " << endl;
    cin >> temp->GetEnglish();
    cout << endl << "Enter new russian word " << endl;
    cin >> temp->GetRussian();

    tree.Edit(temp);
}

void SaveFile(Tree& tree) {
    system("cls");

    Node* temp = tree.GetRoot();
    Node* node = tree.GetRoot();
    char buffer[15];

    FILE* fp;
    fp = fopen("Translate file", "w+");

    int count = 0;
    cout << "Enter count of words: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter word: ";
        cin >> buffer;
        node = tree.Search(tree.GetRoot(), buffer);

        fputs(node->m_english, fp);
        fputs(" - ", fp);
        fputs(node->m_russian, fp);
        fputs("\n", fp);
    }
    getc(fp);

    cout << "File saved" << endl;
    _getch();
}

