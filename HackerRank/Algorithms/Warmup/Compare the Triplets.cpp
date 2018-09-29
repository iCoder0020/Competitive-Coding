/*
ID: iCoder0020
PROG: Compare the Triplets
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main() 
{
    int a[2][3],i,j;
    int A=0,B=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        if(a[0][i]>a[1][i])
        {
            A++;
        }
        if(a[0][i]<a[1][i])
        {
            B++;
        }
    }
    cout<<A<<" "<<B<<"\n";
    return 0;
}
