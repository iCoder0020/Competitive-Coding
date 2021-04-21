#include <bits/stdc++.h>

using namespace std;

#define int long long

int N;
vector<int>g;
vector<vector<int>>g_rev;
vector<bool>vis;
vector<vector<int>>SCC;
vector<int>order;
vector<int>ans;

void dfs1(int v)
{
	if(vis[v])
		return;
	vis[v] = true;
	dfs1(g[v]);
	order.push_back(v);
}

void dfs2(int u, int comp)
{
	if(vis[u])
		return;
	vis[u] = true;
	SCC[comp].push_back(u);
	for(int v: g_rev[u])
		if(!vis[v])
			dfs2(v, comp);
}

int32_t main()
{
	int N;
	cin>>N;
	g.resize(N+1);
	g_rev.resize(N+1);
	ans.resize(N+1);
	for(int n = 1; n<=N; n++)
	{
		int x;
		cin>>x;
		g[n] = x;
		g_rev[x].push_back(n);
		if(n == x)
			ans[n] = 1;
	}
	vis.assign(N+1, false);
	for(int n = 1; n<=N; n++)
		if(!vis[n])
			dfs1(n);

	vis.assign(N+1, false);
	for(int n = N-1; n>=0; n--)
	{
		if(!vis[order[n]])
		{
			vector<int>v;
			SCC.push_back(v);
			dfs2(order[n], SCC.size()-1);
		}
	}

	for(auto comp: SCC)
		for(auto v: comp)
			if(comp.size()>1)
				ans[v] = comp.size();

	for(int n = 0; n<N; n++)
		if(ans[order[n]] == 0)
			ans[order[n]] = 1+ans[g[order[n]]];

	for(int n = 1; n<=N; n++)
		cout<<ans[n]<<" ";
	cout<<endl;
	return 0;
}
