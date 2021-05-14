#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<vector<int>>g(N+1);
	vector<int>dp(N+1, 1);
	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for(int u = 1; u<=N; u++)
	{
		for(int v: g[u])
		{
			if(v>u)
				dp[v] = max(dp[v], dp[u]+1);
		}
		ans = max(ans, (int)g[u].size()*dp[u]);
	}
	cout<<ans<<endl;
	return 0;
}
