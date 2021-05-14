#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<vector<int>>dp(N+1, vector<int>(2*M+1,0));
	for(int m = 1; m<=2*M; m++)
		dp[1][m] = 1;
	for(int n = 1; n<=N; n++)
		dp[n][1] = n;
	for(int n = 2; n<=N; n++)
		for(int m = 2; m<=2*M; m++)
			dp[n][m] = (dp[n][m] + dp[n][m-1] + dp[n-1][m])%MOD;
	cout<<dp[N][2*M]<<endl;
	return 0;
}
