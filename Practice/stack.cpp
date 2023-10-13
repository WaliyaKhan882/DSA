#include <iostream>
using namespace std;

int insert_stack(char *stack, char value, int &top, int size)
{
    int retvalue;
    if (top < size)
    {
        stack[top++]=value;
        retvalue = 1;
    }
    else
    {
        retvalue = 0;
    }
    return retvalue;
}
int remove_stack(char *stack, int &top)
{
    int retvalue;
    if (top > 0)
    {
        cout << stack[--top] << endl;
        retvalue = 1;
    }
    else
    {
        retvalue = 0;
    }
    return retvalue;
}
void traverse_stack(char *stack, int top)
{
    cout << "stack elements are: " << endl;
    for (int i = top-1; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
int main()
{
    int size, top = 0;
    cout << "enter size" << endl;
    cin >> size;
    char *stk=new char[size];
    char value;
    while (1)
    {
        cout << "enter 1 for insertion in stack || 2 for removing from stack || 3 for printing stack || 0 to quit program" << endl;
        int option, indicator = 0, result;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> value;
            result = insert_stack(stk, value, top, size);
            if (result == 0)
            {
                cout << "stack is full" << endl;
            }
            break;
        case 2:
            result = remove_stack(stk, top);
            if (result == 0)
            {
                cout << "stack underflow" << endl;
            }
            break;
        case 3:
            traverse_stack(stk, top);
            break;
        case 0:
            exit(0);
        }
    }
}
