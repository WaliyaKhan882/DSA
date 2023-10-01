// compute transpose of matrix
#include <iostream>
using namespace std;
int main()
{
    int row = 2, column = 2, matrix[row][column] = {{1, 2}, {4, 5}}, transposed[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}