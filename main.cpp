#include <iostream>
#include "binaryTree.cpp"
#include <vector>
#include <fstream>
using namespace std;

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