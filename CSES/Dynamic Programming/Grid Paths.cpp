#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N;
	cin>>N;
	char grid[N][N];
	for(int n = 0; n<N; n++)
		for(int m = 0; m<N; m++)
			cin>>grid[n][m];
	int dp[N][N];
	for(int n = N-1; n>=0; n--)
	{
		for(int m = N-1; m>=0; m--)
		{
			dp[n][m] = 0;
			if(grid[n][m] == '*')
				continue;
			if(n == N-1 && m == N-1)
				dp[n][m] = 1;
 			if(n+1 < N && grid[n+1][m] == '.')
				dp[n][m] = (dp[n][m] + dp[n+1][m])%MOD;
			if(m+1 < N && grid[n][m+1] == '.')
				dp[n][m] = (dp[n][m] + dp[n][m+1])%MOD;
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
}
