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

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    string temp;
    while(getline(inputFile, temp))
    {
        bst.insertNode(temp);
    }



    return 0;
}

int menu()
{

}
