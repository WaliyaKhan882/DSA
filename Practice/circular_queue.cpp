#include <iostream>
using namespace std;

static int nop = 0;

void circular_enqueue(char person, char *que, int &T, int size)
{
    if (nop < size)
    {
        que[T] = person;
        cout << que[T] << endl;
        T = (T + 1) % size;
        cout << T << endl;
        nop++;
    }
    else
    {
        cout << "queue is full" << endl;
    }
}
// used & with T and F so to change value of T and F everywhere (passing address actually)
void circular_dequeue(char person, char *que, int &F, int size)
{
    if (nop > 0)
    {
        cout << que[F] << endl;
        F = (F + 1) % size;
        nop--;
        cout << "dequeu" << endl;
    }
    else
    {
        cout << "queue is empty" << endl;
    }
}

int main()
{
    int size, T = 0, F = 0;
    cout << "enter size" << endl;
    cin >> size;
    char *que = new char[size];
    char *person = (char *)malloc(sizeof(char));

    while (1)
    {
        cout << "enter 1 for insertion in queue || 2 for removing from queue || 3 for printing queue || 0 to quit program" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> person;
            circular_enqueue(*person, que, T, size);
            break;
        case 2:
            circular_dequeue(*person, que, F, size);
            break;
        case 3:
            for (int i = 0; i < nop; i++)
            {
                cout << que[i] << endl;
            }
            break;
        case 0:
            delete[] que;
            exit(0);
        }
    }
}