/*
ID: iCoder0020
PROG: Diagonal Difference
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main() 
{
    int N,a;
    int i,j;
    int sum1=0,sum2=0;
    cin>>N;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>a;
            if(i==j)
                sum1+=a;
            if(i+j==N-1)
                sum2+=a;
        }
    }
    cout<<abs(sum1-sum2)<<"\n";
    return 0;
}
