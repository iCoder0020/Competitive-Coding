#include <bits/stdc++.h>

using namespace std;

#define int long long

bool change(int u, int v, vector<bool>&vis, vector<set<pair<int,int>>>&g)
{
	if(u == v && vis[u])
		return false;
	if(vis[u])
		return true;
	vis[u] = true;
	bool p = false;
	for(auto it: g[u])
	{
		if(it.second == 0)
		{
			cout<<u<<" "<<it.first<<endl;
			g[u].erase({it.first,0});
			g[it.first].insert({u,1});
			return true;
		}
		p|=change(it.first,v,vis,g);
	}
	return p;
}

bool dfs(int u, int v, vector<bool>&vis, vector<set<pair<int,int>>>&g)
{
	if(u == v && vis[u])
		return false;
	if(vis[u])
		return true;
	vis[u] = true;
	bool p = true;
	for(auto it: g[u])
		p&=dfs(it.first,v,vis,g);
	return p;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		vector<set<pair<int,int>>>g(N+1);
		for(int m = 0; m<M; m++)
		{
			int t,x,y;
			cin>>t>>x>>y;
			g[x].insert({y,t});
		}
		vector<bool>vis(N+1, false);
		bool poss = true;
		for(int i = 1; i<=N; i++)
		{
			if(vis[i])
				continue;
			if(!dfs(i, i, vis,g))
			{
				vector<bool>v(N+1, false);
				if(!change(i,i,v,g))
				poss = false;
				break;
			}
				
		}
		if(!poss)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i = 1; i<=N; i++)
				for(auto it: g[i])
					cout<<i<<" "<<it.first<<endl;
		}
	}
	return 0;
}
