#include <iostream>
using namespace std;

struct binSearchTreeNode
{
    binSearchTreeNode *left; //Left node - less
    binSearchTreeNode *right; //Right node - greater
    int data;
};
class binSearchTree
{
    binSearchTreeNode *rootNode;

public:
    binSearchTree()
    {
        rootNode = NULL; //
    }
    bool isempty()
    {
        return (rootNode == NULL);
    }
    void insert(int);
    void displayBinTree();
    void printBinTree(binSearchTreeNode *);
};
void binSearchTree::insert(int item)
{
    binSearchTreeNode *p = new binSearchTreeNode;
    binSearchTreeNode *parent;
    p->data = item;
    p->left = NULL; p->right = NULL;
    parent = NULL;
    if (isempty())
        rootNode = p; //If root node is empty make p the root node
    else
    {
        binSearchTreeNode *ptr;
        ptr = rootNode; //ptr point to root node
        while (ptr != NULL)
        {
            parent = ptr;
            if (item > ptr->data) //if item is greater than ptr's data attribute 
                ptr = ptr->right; //Step into the right node/right child
            else
                ptr = ptr->left; //else Step into the left node/left child
        }
        if (item < parent->data) 
            parent->left = p;
        else
            parent->right = p;
    }
}
void binSearchTree::displayBinTree()
{
    printBinTree(rootNode);
}
void binSearchTree::printBinTree(binSearchTreeNode *ptr)
{
    if (ptr != NULL)
    {
        printBinTree(ptr->left);
        cout << "  " << ptr->data << " ";
        printBinTree(ptr->right);
    }
}

