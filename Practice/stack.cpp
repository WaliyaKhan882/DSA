#include <iostream>
using namespace std;

int insert_stack(int *stack, int value, int top)
{
    top++;
    stack[top] = value;
    cout << stack[top] << endl;
    cout << "value inserted" << endl;
    return top;
}
int remove_stack(int *stack, int top)
{
    cout << stack[top] << endl;
    top--;
    cout << "value popped out" << endl;
    return top;
}
void traverse_stack(int *stack, int top)
{
    cout << "stack elements are: " << endl;
    for (int i = top; i >-1; i--)
    {
        cout << stack[i] << endl;
    }
}
int main()
{
    int size, value,top = -1;
    cout << "enter size" << endl;
    cin >> size;
    int *stk=new int[size];
    while (1)
    {
        cout << "enter 1 for insertion in stack || 2 for removing from stack || 3 for printing stack || 0 to quit program" << endl;
        int option,indicator=0;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> value;
            if(top<size-1){
            indicator=insert_stack(stk, value, top);
            top=indicator;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
            break;
        case 2:
            if(top>-1){
            indicator=remove_stack(stk, top);
            top=indicator;
            }
            else{
                cout<<"stack underflow"<<endl;
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