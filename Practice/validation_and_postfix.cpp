#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

char peek(char *stack, int &top)
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
void insert_stack(char *stack, char value, int &top, int size)
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
void remove_stack(char *stack, int &top)
{
    if (top > 0)
    {
        cout << stack[--top] << endl;
    }
    else
    {
        cout << "stack is empty" << endl;
    }
}
void traverse_stack(char *stack, int &top)
{
    cout << "stack elements are: " << endl;
    for (int i = top - 1; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
bool is_bracket(char x)
{
    int retvalue = false;
    if (x == '(' || x == '{' || x == '[' || x == ')' || x == '}' || x == ']')
    {
        retvalue = true;
    }
    return retvalue;
}
bool is_open_bracket(char x)
{
    int retvalue = false;
    if (x == '(' || x == '{' || x == '[')
    {
        retvalue = true;
    }
    return retvalue;
}
int is_close_bracket(char x)
{
    int retvalue = 0;
    if (x == ')' || x == '}' || x == ']')
    {
        retvalue = 1;
    }
    return retvalue;
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
int is_operator_precedence(char x)
{
    int retvalue = 0;
    switch (x)
    {
    case '^':
        retvalue = 4;
        break;
    case '%':
        retvalue = 3;
        break;
    case '*':
    case '/':
        retvalue = 2;
        break;
    case '-':
    case '+':
        retvalue = 1;
        break;
    }
    return retvalue;
}
int is__open_bracket_precedence(char x)
{
    int retvalue = 0;
    switch (x)
    {
    case '(':
        retvalue = 3;
        break;
    case '{':
        retvalue = 2;
        break;
    case '[':
        retvalue = 1;
        break;
    }
    return retvalue;
}
int is__close_bracket_precedence(char x)
{
    int retvalue = 0;
    switch (x)
    {
    case ')':
        retvalue = 3;
        break;
    case '}':
        retvalue = 2;
        break;
    case ']':
        retvalue = 1;
        break;
    }
    return retvalue;
}
bool valid_expression(char *exp, char *stack, int &top, int size)
{
    bool retvalue = true;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (is_bracket(exp[i]))
        {
            if (is_open_bracket(exp[i]))
            {
                if (isEmpty(top))
                {
                    insert_stack(stack, exp[i], top, size);
                }
                else
                {
                    if (is__open_bracket_precedence(exp[i]) > is__open_bracket_precedence(peek(stack, top)))
                    {
                        insert_stack(stack, exp[i], top, size);
                    }
                    else
                    {
                        retvalue = false;
                    }
                }
            }
            else
            {
                if (isEmpty(top))
                {
                    retvalue = false;
                }
                else
                {
                    switch (exp[i])
                    {
                    case ')':
                        if (stack[top] != '(') // in exam write it as if(pop()!='(')
                        {
                            retvalue = false;
                        }
                        remove_stack(stack, top);
                        break;
                    case '}':
                        if (stack[top] != '{')
                        {
                            retvalue = false;
                        }
                        remove_stack(stack, top);
                        break;
                    case ']':
                        if (stack[top] != '[')
                        {
                            retvalue = false;
                            remove_stack(stack, top);
                        }
                        break;
                    }
                }
            }
        }
    }
    return retvalue;
}
char *infix_to_postfix(char *ie, char *stk, int &top, int size)
{
    int j = 0;
    ie[size] = '\0';

    char *pe = new char[size];
    for (int i = 0; ie[i] != '\0'; i++)
    {
        if (is_operator(ie[i]))
        {
            if (isEmpty(top))
            {
                insert_stack(stk, ie[i], top, size);
            }
            else
            {
                if (is_operator_precedence(ie[i]) > is_operator_precedence(stk[top - 1]))
                {
                    insert_stack(stk, ie[i], top, size);
                }
                else
                {
                    while (!isEmpty(top) && is_operator_precedence(ie[i]) <= is_operator_precedence(peek(stk,top)))
                    {
                        remove_stack(stk, top);
                        pe[j] = stk[top];
                        j++;
                    }
                    insert_stack(stk, ie[i], top, size);
                }
            }
        }
        else
        {
            pe[j] = ie[i];
            j++;
            // in exam strcat(pe,ie[i])
        }
    }
    while (!isEmpty(top))
    {
        remove_stack(stk, top);
        pe[j] = stk[top];
        j++;
    }
    pe[j] = '\0';
    return pe;
}
int main()
{
    int size, top = 0;
    char *exp = new char[size];
    cout << "enter size" << endl;
    cin >> size;
    cout << "enter expression" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> exp[i];
    }
    // infix to postfix
    char *postfix = new char[size];
    char *stack = new char[size];
    postfix = infix_to_postfix(exp, stack, top, size);
    for (int i = 0; i < size; i++)
    {
        cout << postfix[i];
    }
    // validation
    //  bool result = valid_expression(exp, stack, top, size);
    //  if (result == true)
    //  {
    //      cout << "Valid expression" << endl;
    //  }
    //  else
    //  {
    //      cout << "Invalid expression" << endl;
    //  }

    delete[] exp;
    delete[] postfix;
    delete[] stack;
    return 0;
}
