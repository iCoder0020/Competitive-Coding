/*
ID: iCoder0020
PROG: A Very Big Sum
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main() 
{
    long a,sum=0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        sum+=a;
    }
    cout<<sum<<"\n";
    return 0;
}
