#include <iostream>
using namespace std;
// addition of sparse matrix

void add_sparse_matrix(int **a, int **b, int **c)
{
    int count = 0;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] > b[j][0])
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
            count++;
        }
        else if (a[i][0] < b[j][0])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
            count++;
        }
        else if (a[i][0] == b[j][0])
        {
            if (a[i][1] < b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;
                i++;
                count++;
            }
            else if (a[i][1] > b[j][1])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;
                j++;
                count++;
            }
            else if (a[i][1] == b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                int sum = a[i][2] + b[j][2];
                if (sum != 0)
                {
                    c[k][2] = sum;
                    k++;
                    count++;
                }
                i++;
                j++;
            }
        }
    }
    // remaining elements
    if ((a[0][2] + 1) > (b[0][2] + 1))
    {
        for (int l = i; l <= a[0][2]; l++)
        {
            c[k][0] = a[l][0];
            c[k][1] = a[l][1];
            c[k][2] = a[l][2];
            k++;
            count++;
        }
    }
    else if ((a[0][2] + 1) < (b[0][2] + 1))
    {
        for (int l = j; l <= b[0][2]; l++)
        {
            c[k][0] = b[l][0];
            c[k][1] = b[l][1];
            c[k][2] = b[l][2];
            k++;
            count++;
        }
    }
    cout << count << endl;
    c[0][2] = count;
    cout << "result of adding sparse matrix" << endl;
    for (int m = 0; m < k; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            cout << c[m][n] << "  ";
        }
        cout << endl;
    }

    // Free the memory after the use of array
    for (int i = 0; i < a[0][0]; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    for (int i = 0; i < b[0][0]; i++)
    {
        delete[] b[i];
    }
    delete[] b;
}

// transpose

void transpose(int **c, int row, int col)
{
    cout << endl
         << "Transpose of result matrix" << endl;
    int trans[row][col];
    trans[0][0] = c[0][1];
    trans[0][1] = c[0][0];
    trans[0][2] = c[0][2];
    int k = 1;
    for (int m = 1; m <= c[0][2]; m++)
    {
        for (int n = 1; n <= c[0][2]; n++)
        {
            if (m == c[n][1])
            {
                trans[k][0] = c[n][1];
                trans[k][1] = c[n][0];
                trans[k][2] = c[n][2];
                k++;
            }
        }
    }
    for (int m = 0; m <= c[0][2]; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            cout << trans[m][n] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < c[0][0]; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}

int main()
{
    int row1, col1, **a, **b, **c;
    cout << "enter number of rows" << endl;
    cin >> row1;
    cout << "enter number of columns" << endl;
    cin >> col1;
    a = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        a[i] = new int[col1];
    }
    cout << "enter elements for matrix A" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    int row2, col2;
    cout << "enter number of rows" << endl;
    cin >> row2;
    cout << "enter number of columns" << endl;
    cin >> col2;
    b = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        b[i] = new int[col2];
    }
    cout << "enter elements for matrix B" << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << b[i][j] << "  ";
        }
        cout << endl;
    }
    int row = row1 + row2, col = 3;
    c = new int *[row];
    for (int i = 0; i < row; i++)
    {
        c[i] = new int[col];
    }
    add_sparse_matrix(a, b, c);
    transpose(c, row, col);
}