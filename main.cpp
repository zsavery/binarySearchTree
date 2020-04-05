#include <iostream>
#include "binaryTree.cpp"
using namespace std;

int main()
{
    binSearchTree b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30);

    cout << "Binary tree created: " << endl;
    b.displayBinTree();
}