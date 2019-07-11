/*
ID: iCoder0020
PROG: k-Tree
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N,K,D;
	cin>>N>>K>>D;
	vector<vector<int>>dp(N+1, vector<int>(2, 0));
	int zero = 0;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int n = 1; n<=N; n++)
	{
		for(int i = max(zero, n-D+1); i<=n-1; i++)
			dp[n][0] = (dp[n][0] + dp[i][0])%MOD;
		for(int i = max(zero, n-K); i<=n-1; i++)
			dp[n][1] = (dp[n][1] + dp[i][1])%MOD;
		for(int i = max(zero, n-K); i<=n-D; i++)
			dp[n][1] = (dp[n][1] + dp[i][0])%MOD;
	}
	cout<<dp[N][1]<<endl;
	return 0;
}