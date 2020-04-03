#include <bits/stdc++.h>

using namespace std;

#define int long long

int inc(int x, int L, int R, int H)
{
	int y = (x+H)%H;
	if(y>=L && y<=R)
		return 1;
	return 0;
}

int32_t main()
{
	int N,H,L,R;
	cin>>N>>H>>L>>R;
	int A[N+1];
	int prefix[N+1] = {0};
	for(int n = 1; n<=N; n++)
	{
		cin>>A[n];
		prefix[n] = prefix[n-1]+A[n];
	}
	vector<vector<int>>dp(N+1, vector<int>(N+1, 0));
	//dp[i][j]-> 	max # of good sleeping times if slept earlier 
	//				j times out of first i times

	for(int i = 1; i<=N; i++)
	{
		for(int j = 0; j<=i; j++)
		{
			dp[i][j] = dp[i-1][j] + inc(prefix[i]-j, L, R, H);
			if(j>0)
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + inc(prefix[i]-j, L, R, H));	
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}

	int ans = 0;
	for(int j = 0; j<=N; j++)
		ans = max(ans, dp[N][j]);
	cout<<ans<<endl;
	return 0;
}
