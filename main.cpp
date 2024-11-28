#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream inputFile("codes.txt");

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return;
    }

    string temp;
    while(getline(inputFile, temp))
    {
        insertNode(temp);
    }

    return 0;
}
