/*
ID: iCoder0020
PROG: Left Rotation
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,D;
    cin>>N>>D;
    int A[N];
    for(int n = 0; n<N; n++)
    {
    	cin>>A[n];
    }
    for(int n = D%N; n<N; n++)
    {
    	cout<<A[n]<<" ";
    }
    for(int n = 0; n<D%N; n++)
    {
    	cout<<A[n]<<" ";
    }
    cout<<endl;
    return 0;
}