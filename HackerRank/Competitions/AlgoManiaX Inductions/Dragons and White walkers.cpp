/*
ID: f20170069
PROG: Dragons and White walkers
LANG: C++                  
*/

#include <iostream>

using namespace std;

int N;

int main()
{
    int k=0;
    cin>>N;
    while(N%2==0)
    {
        k++;
        N/=2;
    }
    cout<<k<<"\n";
    return 0;
}
