/*
ID: iCoder0020
PROG: Yet Another Subarray Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,M,K;
	cin>>N>>M>>K;
	int A[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	int fix[N+1] = {0};
	for(int n = 1; n<=N; n++)
	{
		if(n%M == 0)
			fix[n] = k*(n/M);
		else
			fix[n] = k*(n/M+1)
	}
	
	cout<<max(fix[0], ans)<<endl;
	return 0;
}