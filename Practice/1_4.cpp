// compute determinant of 2x2 matrix
#include<iostream>
using namespace std;
int main(){
   int matrix[2][2]={{1,2},{3,4}},d=1,m=1;
   for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        if(i==j){
            d*=matrix[i][j];
        }
        else{
            m*=matrix[i][j];
        }
    }
   }
   int det=d-m;
   cout<<det<<endl;
}