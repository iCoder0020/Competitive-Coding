#include <bits/stdc++.h>

using namespace std;

#define int long long

void farthest_helper(int u, vector<vector<int>>&g, vector<bool>&vis, int d, pair<int,int>&ans)
{
	if(vis[u])
		return;
	if(d>ans.second)
		ans = {u,d};
	vis[u] = true;
	for(auto v: g[u])
	{
		if(vis[v])
			continue;
		farthest_helper(v, g, vis, d+1, ans);
	}
}

pair<int, int> farthest_node(vector<vector<int>>&g, int u)
{
	pair<int, int> ans = {u, 0};
	vector<bool>vis(g.size(), false);
	farthest_helper(u, g, vis, 0, ans);
	return ans;
}

void path_helper(int u, int v, vector<vector<int>>&g, vector<bool>&vis, vector<int>&path, bool &done)
{
	if(vis[u])
		return;
	vis[u] = true;
	path.push_back(u);
	if(u == v)
	{
		done = true;
		return;
	}
	for(auto it: g[u])
	{
		if(vis[it])
			continue;
		path_helper(it,v,g,vis,path,done);
		if(done)
			return;
	}
	path.pop_back();
}

vector<int> get_path(vector<vector<int>>&g, int u, int v)
{
	vector<int>path;
	vector<bool>vis(g.size(), false);
	bool done = false;
	path_helper(u,v,g,vis,path,done);
	return path;
}

void aux_helper(int u, int next, vector<pair<int,int>>&aux, vector<vector<int>>&g, vector<bool>&vis)
{
	if(vis[u])
		return;
	vis[u] = true;
	for(auto it: g[u])
	{
		if(vis[it] || it == next)
			continue;
		aux[it] = {aux[u].first+1, aux[u].second};
		aux_helper(it, next, aux, g, vis);
	}
}

vector<pair<int,int>> get_aux(vector<vector<int>>&g, vector<int>&path)
{
	int psize = path.size();
	vector<pair<int,int>>aux(g.size());
	vector<bool>vis(g.size(), false);
	for(int i = 0; i<psize; i++)
	{
		int u = path[i];
		aux[u] = {0, min(i,psize-i-1)};
		aux_helper(u, path[i+1], aux, g, vis);
	}
	return aux;
}

int32_t main()
{
	int N;
	cin>>N;
	vector<vector<int>>g(N+1);
	for(int n = 0; n<N-1; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pair<int, int>p1 = farthest_node(g, 1);
	pair<int, int>p2 = farthest_node(g, p1.first);
	int d = p2.second;
	vector<int> path = get_path(g, p1.first, p2.first);
	vector<pair<int,int>> aux = get_aux(g, path);
	for(int n = 1; n<=N; n++)
	{
		if(aux[n].first+1>aux[n].second)
			cout<<d+1;
		else
			cout<<d;
		cout<<endl;
	}
	return 0;
}