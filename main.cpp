#include <iostream>
#include "binaryTree.cpp"
#include <vector>
#include <fstream>
using namespace std;
//Created by Zyon Savery 4/5/2020

int main()
{
    binSearchTree b;
    vector <int> dataList;

    ifstream dataFile("dataSet.txt");
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            int data; 
            dataFile >> data;
            b.insert(data);
            //cout << data << endl;
            
        }
        //b.makeSortedList();
        b.displayBinTree();
        cout << endl;
    }  
    dataFile.close();
    

    
}