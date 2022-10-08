#include <iostream>
#include<cstdio>
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

    getchar();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Write to the file\n6. Edit\n7. Exit\n";

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

void Edit(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (&node != nullptr)
    {
        cout << "Enter russian translation\n";
        char text[15]={};
        cin >> text;
        node->SetRussian(text);
    }
    else
    {
        cout << "Word not found" << endl;
    }

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

    
}

void toFile(const Tree& tree, const char* path) {
    FILE* file;
    errno_t error = fopen_s(&file, path, "w");
    if (error!=0) {
        cout << "Error opening file for output\n";
        return;
    }
    Node *node = tree.GetRoot();

    tree.getNodeToF(tree.GetRoot(), file);

    fclose(file);
}