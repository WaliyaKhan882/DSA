// 2D array dynamic allocation with pointers
#include <iostream>
using namespace std;
int main()
{
    int **matrix, row = 3, column = 2;
    matrix = new int*[row];
    for (int i = 0; i < row; i++) // allocating column space in heap dynamically
    {
        matrix[i] = new int[column];
    }
    cout << "enter elements" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    // Free the memory after the use of array
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
