//detect either a matrix is sparse or not
#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    int matrix[3][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0}},count=0;bool sparse;float two_third=2.0/3.0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                count++;
            }
        }
    }
    // cout<<count<<endl;
    int row=3,column=4;
    int size=row*column;
    // cout<<setprecision(2)<<two_third<<endl;
    // cout<<setprecision(2)<<size*two_third<<endl;
    if((count)>(size*two_third)){
        sparse=true;
    }
    else{
        sparse=false;
    }
    cout<<sparse<<endl;
}