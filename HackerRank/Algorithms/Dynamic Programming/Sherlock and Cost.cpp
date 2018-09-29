/*
ID: iCoder0020
PROG: Sherlock and Cost
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N;
    cin>>T;
    long long int S;
    for(int t = 0; t<T; t++)
    {
    	cin>>N;
    	S = 0;
    	int A_min[N];
    	int A_max[N];
    	int B[N];
    	for(int n = 0; n<N; n++)
    	{
    		cin>>B[n];
    		A_min[n] = 1;
    		A_max[n] = B[n];
    	}
    	for(int i = 2; i<N; i++)
    	{
    		S += max(abs(A_max[i]-A_m))
    	}
    }
    return 0;
}
