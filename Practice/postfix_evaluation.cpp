#include <iostream>
#include<math.h>
using namespace std;

int peek(int *stack, int &top)
{
    return stack[top-1];
}
bool isEmpty(int &top)
{
    bool retvalue = false;
    if (top < 1)
    {
        retvalue = true;
    }
    return retvalue;
}
bool is_full(int &top, int size)
{
    bool retvalue = false;
    if (top > size)
    {
        retvalue = true;
    }
    return retvalue;
}
void insert_stack(int *stack, int value, int &top, int size)
{
    if (top < size)
    {
        stack[top++] = value;
    }
    else
    {
        cout << "stack is full" << endl;
    }
}
int remove_stack(int *stack, int &top)
{
    int val=0;
    if (top > 0)
    {
        val=stack[--top];
    }
    else
    {
        cout << "stack is empty" << endl;
    }
    return val;
}
void traverse_stack(int *stack, int &top)
{
    cout << "stack elements are: " << endl;
    for (int i = peek(stack,top); i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
bool is_operator(char x)
{
    bool retvalue = false;
    if (x == '^' || x == '%' || x == '*' || x == '/' || x == '+' || x == '-')
    {
        retvalue = true;
    }
    return retvalue;
}
int postfix_evaluation(const char *pe,int *stack,int &top,int size){
    int result=0;
    for(int i=0;pe[i]!='\0';i++){
        if(isdigit(pe[i])){
            insert_stack(stack,int(pe[i]-48),top,size);
        }
        else{
          if(is_operator(pe[i])){
            int val1=remove_stack(stack,top);
            int val2=remove_stack(stack,top);
            switch(pe[i]){
                case '+':
                result=val2+val1;
                break;
                case '-':
                result=val2-val1;
                break;
                case '*':
                result=val2*val1;
                break;
                case '/':
                result=val2/val1;
                break;
                case '%':
                result=val2%val1;
                break;
                case '^':
                result=pow(val2,val1);
                break;
            }
            insert_stack(stack,result,top,size);
          }
        }
    }
    return result;
}
int main(){
     int top = 0,size=15;
    const char *pe = "342^9%*652^/3*-";
    int *stack = new int[size];
    int result=postfix_evaluation(pe,stack,top,size);
    cout<<"result   "<<result<<endl;
}