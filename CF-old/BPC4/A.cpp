#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,K;
	cin>>N>>K;
	int A[N+1];
	for(int n = 1; n<=N; n++)
		cin>>A[n];

	vector<int>opp(N+1, 0);
	int pos, neg;
	pos = neg = 0;
	for(int n = 1; n<=N; n++)
	{	
		if(A[n] > 0)
		{
			pos = n;
			opp[n] = neg;
		}
		if(A[n] < 0)
		{
			neg = n;
			opp[n] = pos;
		}
	}

	// for(auto it: opp)
	// 	cout<<it<<" ";
	// cout<<endl;

	vector<pair<int,int>>end(N+2,{0,0});
	for(int n = 1; n<=N; n++)
	{
		if(A[n]+end[n-1].first > A[n] && A[n]+end[n-1].first > 0)
			end[n] = {A[n]+end[n-1].first, end[n-1].second};
		else
			end[n] = {max(0LL, A[n]), n};
		// cout<<end[n].first<<" "<<end[n].second<<endl;
	}

	vector<pair<int,int>>endK(N+2,{0,0});
	for(int n = 1; n<=N; n++)
	{
		if(A[n]*K+endK[n-1].first > A[n]*K && A[n]*K+endK[n-1].first > 0)
			endK[n] = {A[n]*K+endK[n-1].first, endK[n-1].second};
		else
			endK[n] = {max(0LL, A[n]*K), n};
		// cout<<endK[n].first<<" "<<endK[n].second<<endl;
	}
	
	vector<vector<int>>dp(N+1, vector<int>(2,0));
	//dp[i][j] -> maxm answer if answer subarray ends at i using j subarrays 

	int ans = 0;
	for(int i = 1; i<=N; i++)
	{
		dp[i][0] = max({end[i].first + dp[end[i].second-1][0], 
						end[i].first - end[opp[i]].first + dp[opp[i]][0]});

		// if(i == 5)
		// 	cout<<end[opp[i]].first<<endl;

		dp[i][1] = max({endK[i].first + dp[endK[i].second-1][0], 
						end[i].first + dp[end[i].second-1][1],
						endK[i].first - endK[opp[i]].first + dp[opp[i]][0], 
						end[i].first - end[opp[i]].first + dp[opp[i]][1]});

		ans = max({ans, dp[i][0], dp[i][1]});
		// cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
