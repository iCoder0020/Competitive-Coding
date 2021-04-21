#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>

int N,M,S;
vector<vector<pii>>g;
vector<int>vis;
vector<pii>edges;
map<pii,char>DIR1;
map<pii,char>DIR2;
int cnt;

void dfs1(int u)
{
	if(vis[u])
		return;
	vis[u] = true;
	cnt++;
	for(auto v: g[u])
	{
		if(vis[v.second])
			continue;
		if(v.first == 1)
			dfs1(v.second);
		if(v.first == 2)
		{
			pii e = {u,v.second};
			bool f = true;
			if(DIR1.find(e)==DIR1.end())
			{
				e = {v.second,u};
				f = false;
			}
			if(DIR1[e] != '?')
				continue;
			if(f)
				DIR1[e] = '+';
			else
				DIR1[e] = '-';
			dfs1(v.second);
		}
	}
}

void dfs2(int u)
{
	if(vis[u])
		return;
	vis[u] = true;
	cnt++;
	for(auto v: g[u])
	{
		if(vis[v.second])
			continue;
		if(v.first == 1)
			dfs2(v.second);
		if(v.first == 2)
		{
			pii e = {u,v.second};
			bool f = true;
			if(DIR2.find(e)==DIR2.end())
			{
				e = {v.second,u};
				f = false;
			}
			if(DIR2[e] != '?')
				continue;
			if(f)
				DIR2[e] = '-';
			else
				DIR2[e] = '+';
		}
	}
}

int32_t main()
{
	cin>>N>>M>>S;
	g.resize(N+1);
	for(int m = 0; m<M; m++)
	{
		int t,u,v;
		cin>>t>>u>>v;
		if(t == 1)
			g[u].push_back({1,v});
		else
		{
			g[u].push_back({2,v});
			g[v].push_back({2,u});
			DIR1[{u,v}] = '?';
			DIR2[{u,v}] = '?';
			edges.push_back({u,v});
		}
	}

	cnt = 0;
	vis.resize(N+1,false);
	dfs1(S);
	cout<<cnt<<endl;
	for(auto it: edges)
	{
		if(DIR1[it] == '?')
			DIR1[it] = '+';
		cout<<DIR1[it];
	}
	cout<<endl;

	cnt = 0;
	for(int n = 0; n<=N; n++)
		vis[n] = false;
	dfs2(S);
	cout<<cnt<<endl;
	for(auto it: edges)
	{
		if(DIR2[it] == '?')
			DIR2[it] = '+';
		cout<<DIR2[it];
	}
	cout<<endl;
	return 0;
}
