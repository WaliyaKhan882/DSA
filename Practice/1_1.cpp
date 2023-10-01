//compute the frequency of alphabets
#include <iostream>
using namespace std;
#define MAX_SIZE CHAR_MAX
int main()
{
    char *alpha = new char();
    int count[26] = {0};
    cout << "enter the string" << endl;
    cin.getline(alpha,MAX_SIZE);
    for (int i = 0; alpha[i] != '\0'; i++)
    {
        count[alpha[i] - 'A']++;
        if (count[alpha[i] - 'A'] > 1)
        {
            alpha[i] = '\n';
        }
    }
    char temp;
    for(int i = 0; alpha[i] != '\0'; i++){
        for(int j =i+1 ; alpha[j] != '\0'; j++){
            if(alpha[i]>alpha[j]){
                temp=alpha[i];
                alpha[i]=alpha[j];
                alpha[j]=temp;
            }
        }
    }
    // for(int i=0;i<26;i++){
    //     cout<<count[i]<<endl;
    // }
    for (int i = 0; alpha[i] != '\0'; i++)
    {
        if (alpha[i] != '\n')
        {
            cout << "count of " << alpha[i] << " is " << count[alpha[i] - 'A'] << endl;
        }
    }
    return 0;
}