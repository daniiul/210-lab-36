// COMSC-210 | 210-lab-38 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include "IntBinaryTree.h"
#include "IntBinaryTree.cpp"
#include <fstream>
#include <string>
using namespace std;

int menu();

int main() {

    IntBinaryTree bst;

    ifstream inputFile("codes.txt");
    // checks if file is open
    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    // reads the codes from the file into the binary tree
    string temp;
    while(getline(inputFile, temp))
    {
        bst.insertNode(temp);
    }

    // simulates the menu
    int in = menu();
    // runs program until user exits
    while(in != 5)
    {
        // add a node
        if(in == 1)
        {
            string code;
            cout << "What would you like to insert: ";
            cin >> code;
            bst.insertNode(code);
        }
        // deletes a node
        else if (in == 2)
        {
            string code;
            cout << "Which code would you like to delete: ";
            cin >> code;
            bst.remove(code);
        }
        // finds a node
        else if (in == 3)
        {
            string code;
            cout << "Which node would you like to find: ";
            cin >> code;
            bool found = bst.searchNode(code);
            if(found == true)
                cout << "Node has been found !";
            else
                cout << "Node has not been found.";
        }
        // modifies a node
        else if (in == 4)
        {
            string code;
            string newcode;
            cout << "Which node would you like to modify: ";
            cin >> code;
            bool found = bst.searchNode(code);
            if(found == true)
            {
                cout << "What would you like to put into it: ";
                cin >> newcode;
                bst.modifyNode(code, newcode);
            }
            else
                cout << "Node has not been found.";
        }
        cout << endl;
        in = menu();
    }

    return 0;
}

// displays the menu
// arguments: none
// returns: integer that represents choice user made
int menu()
{
    int entry;
    cout << "Binary Tree Menu:" << endl;
    cout << "       [1] Add a node" << endl;
    cout << "       [2] Delete a node" << endl;
    cout << "       [3] Find a node" << endl;
    cout << "       [4] Modify a node" << endl;
    cout << "       [5] Exit" << endl;
    do{
        cout << "Enter: ";
        cin >> entry;
    } while(entry < 0 || entry > 5);

    return entry;
}
