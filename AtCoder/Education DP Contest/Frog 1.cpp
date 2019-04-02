/*
ID: iCoder0020
PROG: Frog 1
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int H[N];
	for(int n = 0; n<N; n++)
	{
		cin>>H[n];
	}
	int dp[N+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = abs(H[1]-H[0]);
	for(int n = 3; n<=N; n++)
	{
		dp[n] = min(dp[n-1] + abs(H[n-1]-H[n-2]), dp[n-2] + abs(H[n-1]-H[n-3]));
	}
	cout<<dp[N]<<endl;
	return 0;	
}
