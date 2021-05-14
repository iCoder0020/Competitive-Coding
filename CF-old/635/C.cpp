#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>>g;
vector<pair<int,int>>v;
vector<int>dist;
vector<int>sub;

void dfs(int u, int f)
{
	for(auto it: g[u])
	{	
		if(it == f)
			continue;
		dist[it] = dist[u]+1;
		dfs(it , u);
		sub[u] += sub[it];
	}
	v.push_back({dist[u]-sub[u], u});
	sub[u]++;
}

bool mysort(pair<int,int>&A,pair<int,int>&B)
{
	return A.first>B.first;
}

int32_t main()
{
	int N,K;
	cin>>N>>K;
	g.resize(N+1);
	dist.resize(N+1,0);
	sub.resize(N+1,0);
	for(int n = 0; n<N-1; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1,0);
	for(auto it: sub)
		cout<<it<<" ";
	sort(v.begin(), v.end(), mysort);
	int ans = 0;
	for(int i = 0; i<K; i++)
	{
		if(v[i].second == 0)
			i++;
		ans += v[i].first;
	}
	cout<<ans<<endl;
	return 0;
}
