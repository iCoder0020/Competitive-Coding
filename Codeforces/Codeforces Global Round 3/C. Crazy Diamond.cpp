/*
ID: iCoder0020
PROG: Crazy Diamond
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N+1];
	for(int n = 1; n<=N; n++)
		cin>>A[n];
	for(int n = 1; n<=N; n++)
	{
		if(A[n] != n)
		{
			A[A[n]] = A[n];
		}
	}
	return 0;
}