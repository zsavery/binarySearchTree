#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
//Created by Zyon Savery 4/5/2020

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
    vector<int> dataSortedList;
    binSearchTree()
    {
        rootNode = NULL; //
    }
    bool isempty()
    {
        return (rootNode == NULL);
    }
    void insert(int);
    void makeSortedList();
    void displayBinTree();
    void printBinTree(binSearchTreeNode *);
    vector<int> addSortedToFile(binSearchTreeNode *);
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
    makeSortedList();
    printBinTree(rootNode);
}
void binSearchTree::printBinTree(binSearchTreeNode *ptr)
{

    for (int index = 0; index < dataSortedList.size(); index++)
    {
        if (index == 0 && dataSortedList.size() != index)
            cout << "[" << dataSortedList[index] << ", ";
        else if (dataSortedList.size()-1 == index)
            cout << dataSortedList[index] << "]\n";
        else
            cout << dataSortedList[index] << ", ";
        
    }
}
void binSearchTree::makeSortedList()
{
    
    ofstream sortedDataFile("sortedDataFile.txt");

    dataSortedList = addSortedToFile(rootNode);
    for (int index = 0; index < dataSortedList.size(); index++)
    {
        sortedDataFile << dataSortedList[index] << " ";
    }
        

    sortedDataFile.close();
}

vector <int> binSearchTree::addSortedToFile(binSearchTreeNode *ptr)
{
    //vector <int> dataSortedList;
    
    if (ptr != NULL)
    {
        addSortedToFile(ptr->left);
        dataSortedList.push_back(ptr->data);
        addSortedToFile(ptr->right);
    }
    return dataSortedList;
}