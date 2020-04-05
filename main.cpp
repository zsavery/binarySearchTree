#include <iostream>
#include "binaryTree.cpp"
#include <fstream>
using namespace std;

int main()
{
    binSearchTree b;

    ifstream dataFile("dataSet.txt");
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            int data; 
            dataFile >> data;
            
        }
    }
    dataFile.close();
    

    
}