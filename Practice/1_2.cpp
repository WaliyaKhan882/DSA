// determinant of 2 X 2 matrix
#include <iostream>
using namespace std;
int main(){
    int matrix[2][2]={{2,3},{4,5}},mul1=1,mul2=1;
    for(int i=0;i<2;i++){
       for(int j=0;j<2;j++){
        cout<<matrix[i][j]<<" ";
       } 
       cout<<endl;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==j){
                mul1*=matrix[i][j];
            }
            else{
                mul2*=matrix[i][j];
            }
        }
    }
    int det=mul1-mul2;
    cout<<"determinant is "<<det<<endl;
}