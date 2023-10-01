//using pointer in 1d array

#include<iostream>
using namespace std;

int main(){
    int *p; //pointer to integer or we can say it stores the address of variable whose data type is int
    int b=10;
    p=&b; //if b was an array we can write p=b because array has a base address
    cout<<b<<endl; //prints 10
    cout<<&b<<endl; //prints b address in hexa decimal
    cout<<*p<<endl;//prints 10

    int *x;
    int a[]={1,2,3,4,5};
    x=a;
    cout<<2[a]<<endl; //prints 3 similar to a[2]
    cout<<a<<endl; //prints array base address let's say 100
    cout<<a+1<<endl; //prints address of 2nd array element that will be 104 acc to above 100 base address 
    cout<<*x<<endl;//prints the first element
    //because +1 means increment in memory and for int it takes 4 bytes
    for(int i=0;i<5;i++){
        cout<<*(x+i)<<endl; //prints array elements similar to *(a+i) or i[a] or i[q]
    }
    cout<<*(a+1)<<endl; //prints the 2nd value
    cout<<*a+1<<endl;//add 1 to the first value
}

