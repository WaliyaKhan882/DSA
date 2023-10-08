// sum of product of rows of a square matrix of order 'n' store the result in first column of matrix

#include <iostream>
using namespace std;

int main()
{
    int size, product = 1, **arr=new int*();
    cout << "enter the size of matrix" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        arr[i]=new int();
    }
    cout << "enter elements" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        product = 1;
        for (int j = 0; j < size; j++)
        {
            product *=arr[i][j];
        }
        arr[i][0]=product;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<size;i++){
        delete [] arr[i];
    }
    delete [] arr;
}