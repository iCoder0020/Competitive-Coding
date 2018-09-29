/*
ID: iCoder0020
PROG: Simple Array Sum
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main() 
{
    int sum=0,N,a;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        sum+=a;
    }
    cout<<sum<<"\n";
    return 0;
}
