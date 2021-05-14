#include <bits/stdc++.h>

using namespace std;

#define int long long

int N,M,TW;
vector<int>W;
vector<int>B;
vector<vector<int>>g;
vector<vector<int>>DP;
vector<int>comp;
vector<pair<int,int>>full_group;
vector<vector<int>>full_group_members;

void dfs(int u, int c)
{
	if(comp[u] != 0)
		return;
	comp[u] = c;
	for(int v: g[u])
		dfs(v,c);
}

int32_t main()
{
	cin>>N>>M>>TW;
	W.resize(N+1);
	B.resize(N+1);
	g.resize(N+1);
	for(int n = 1; n<=N; n++)
		cin>>W[n];
	for(int n = 1; n<=N; n++)
		cin>>B[n];
	for(int m = 0; m<M; m++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int NC = 0;
	comp.resize(N+1, 0);
	for(int n = 1; n<=N; n++)
	{
		if(comp[n] == 0)
		{
			NC++;
			dfs(n, NC);
		}
	}

	full_group.resize(NC+1, {0,0});
	full_group_members.resize(NC+1);

	for(int n = 1; n<=N; n++)
	{
		full_group[comp[n]] = {full_group[comp[n]].first + W[n], full_group[comp[n]].second + B[n]};
		full_group_members[comp[n]].push_back(n);
	}

	DP.resize(NC+1, vector<int>(TW+1, 0));

	for(int n = 1; n<=NC; n++)
	{
		for(int w = 0; w<=TW; w++)
		{
			if(full_group[n].first <= w)
				DP[n][w] = DP[n-1][w-full_group[n].first] + full_group[n].second;
			for(int member: full_group_members[n])
				if(W[member] <= w)
					DP[n][w] = max(DP[n][w], DP[n-1][w-W[member]]+B[member]);
			DP[n][w] = max(DP[n][w], DP[n-1][w]);
		}
	}
	cout<<DP[NC][TW]<<endl;
	return 0;
}
