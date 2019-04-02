/*
ID: iCoder0020
PROG: Frog 2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int N,K;
	cin>>N>>K;
	li H[N];
	for(int n = 0; n<N; n++)
	{
		cin>>H[n];
	}
	li dp[N+1];
	dp[0] = 0;
	dp[1] = 0;
	for(int n = 2; n<=min(N,K); n++)
	{
		dp[n] = abs(H[n-1] - H[0]);
		for(int m = 1; m<n; m++)
		{
			dp[n] = min(dp[n], dp[n-m] + abs(H[n-1]-H[n-m-1]));
		}
	}
	for(int n = K+1; n<=N; n++)
	{
		dp[n] = INT_MAX;
		for(int m = 1; m<=K; m++)
		{
			dp[n] = min(dp[n], dp[n-m] + abs(H[n-1]-H[n-m-1]));
		}
	}
	cout<<dp[N]<<endl;
	return 0;	
}
