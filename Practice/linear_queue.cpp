#include <iostream>
using namespace std;
#define SIZE 3

// variables
char *queue = new char[SIZE];

int front = 0;
int rear = 0;

// prototyping
void enqueue(char x);
char dequeue();
bool isEmpty();
bool isFull();
void display();

int main()
{
    char value;
    while (1)
    {
        cout << "enter 1 for insertion in queue || 2 for removing from queue || 3 for printing queue || 0 to quit program" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}

// definitions
bool isFull()
{
    bool ret = false;
    if (front == 0 && rear == SIZE)
    {
        cout << "queue is full" << endl;
        ret = true;
    }
    return ret;
}
bool isEmpty()
{
    bool ret = false;
    if (front == 0 && rear == 0)
    {
        ret = true;
        cout << "queue is empty" << endl;
    }
    return ret;
}
void enqueue(char x)
{
    if (!isFull())
    {
        queue[rear++] = x;
    }
}
char dequeue()
{
    char ret;
    if (!isEmpty())
    {
        ret = queue[front++];
        if (rear == front)
        {
            rear = front = 0;
        }
    }
    return ret;
}
void display()
{
    int val=front;
    for (int i = val; i < rear; i++)
    {
        cout << queue[val] << endl;
        val++;
    }
}
