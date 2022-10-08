//#include <conio.h>
#include <iostream>
#include <conio.h>
#include "Functions.h"
#include "Tree.h"

static int a;

using namespace std;

int main()
{
    cout << a;

    Tree tree;

    bool exit = false;

    for (;;)
    {
        PrintMenu();

        int choice = getchar();

        switch (choice)
        {
        case '1':
            Insert(tree);
            break;
        case '2':
            Remove(tree);
            break;
        case '3':
            Print(tree);
            getchar();
            break;
        case '4':
            Search(tree);
            getchar();
            break;
        case '5':
            toFile(tree, "C:\\projects\\vocab.txt");
            break;
        case '6':
            Edit(tree);
           // getchar();
            break;
        case '7':
            exit = true;
            break;
        }

        if (exit)
        {
            break;
        }
    }

    return 0;
}