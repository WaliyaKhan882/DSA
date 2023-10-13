#include <iostream>
#include <cstring>
using namespace std;

void insert_stack(char *stack, char value, int &top, int size)
{
    int retvalue;
    if (top < size)
    {
        stack[top++]=value;
    }
    else
    {
        cout<<"stack is full"<<endl;
    }
}
void remove_stack(char *stack, int &top)
{
    if (top > 0)
    {
        cout << stack[--top] << endl;
    }
    else
    {
        cout<<"stack is empty"<<endl;
    }
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
        int option, indicator = 0;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> value;
            insert_stack(stk, value, top, size);
            break;
        case 2:
            remove_stack(stk, top);
            break;
        case 3:
            traverse_stack(stk, top);
            break;
        case 0:
            exit(0);
        }
    }
}
