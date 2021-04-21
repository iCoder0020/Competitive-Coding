#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e16

int32_t main()
{
	int N;
	cin>>N;
	int C[N];
	string S[N];
	string revS[N];
	for(int n = 0; n<N; n++)
		cin>>C[n];
	for(int n = 0; n<N; n++)
	{
		cin>>S[n];
		revS[n] = S[n];
		reverse(revS[n].begin(), revS[n].end());
	}
	vector<vector<int>>DP(N, vector<int>(2,INF));
	DP[0][0] = 0;
	DP[0][1] = C[0];
	for(int n = 1; n<N; n++)
	{
		if(DP[n-1][0] != INF && S[n]>=S[n-1])
			DP[n][0] = min(DP[n][0], DP[n-1][0]);
		if(DP[n-1][1] != INF && S[n]>=revS[n-1])
			DP[n][0] = min(DP[n][0], DP[n-1][1]);
		if(DP[n-1][0] != INF && revS[n]>=S[n-1])
			DP[n][1] = min(DP[n][1], DP[n-1][0]+C[n]);
		if(DP[n-1][1] != INF && revS[n]>=revS[n-1])
			DP[n][1] = min(DP[n][1], DP[n-1][1]+C[n]);
		// cout<<DP[n][0]<<" "<<DP[n][1]<<endl;
	}
	int ans = min(DP[N-1][0], DP[N-1][1]);
	if(ans == INF)
		cout<<"-1";
	else
		cout<<ans;
	cout<<endl;
	return 0;
}
