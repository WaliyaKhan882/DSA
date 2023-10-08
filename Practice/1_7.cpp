// dynamic allocation of 1D array using malloc and pointers
#include <iostream>
using namespace std;

int main()
{
    int sum,n=5;
    // dynamic allocation of 1D array
    int *arr=new int[n];
    // arr = (int *)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
        sum +=arr[i];
    }
    printf("The elements: ");
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<endl;
    }
    
  cout<<"sum is"<<sum<<endl;
  cout<<arr<<endl;//hexadecimal base address
  cout<<*arr<<endl;//first element
  free(arr);
  cout<<"memory deallocated"<<endl;
  
}
