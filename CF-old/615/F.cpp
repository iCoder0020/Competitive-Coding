#include <bits/stdc++.h>

using namespace std;

#define int long long

int N;
vector<vector<int>>g;

void DFSUtil(int u, vector<bool>&vis, pair<int,int> curr, pair<int,int>&ans)
{
	vis[u] = true;
	for(auto it: g[u])
	{
		if(!vis[it])
		{
			if(curr.second+1 > ans.second)
				ans = {it, curr.second+1};
			DFSUtil(it, vis, {it, curr.second+1}, ans);
		}
	}
}

pair<int,int> DFS(int u)
{
	pair<int,int> ans, curr;
	vector<bool>vis(N+1, false);
	ans = {u, 0};
	curr = {u, 0};
	DFSUtil(u, vis, curr, ans);
	return ans;
}

void find_path(int curr, int v, vector<int> &path, vector<int>&fpath, vector<bool> &vis)
{
	path.push_back(curr);
	vis[curr] = true;
	if(curr == v)
	{
		fpath = path;
		return;
	}
	for(auto it: g[curr])
	{
		if(!vis[it])
			find_path(it, v, path, fpath, vis);
	}
	path.pop_back();
	vis[curr] = false;
}

int32_t main()
{
	cin>>N;
	g.resize(N+1);
	for(int i = 1; i<N; i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	pair<int,int>p = DFS(1);
	pair<int,int>q = DFS(p.first);

	vector<int>path;
	vector<int>fpath;

	vector<bool> vis(N+1, false);
	find_path(p.first, q.first, path, fpath, vis);

	vis.resize(N+1, false);

	queue<pair<int,int>>Q;

	for(auto it: fpath)
	{
		Q.push({it, 0});
		vis[it] = true;
	}
	
	int x = fpath[1], y = 0;

	while(!Q.empty())
	{
		int u = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		vis[u] = true;
		if(d > y)
		{
			x = u;
			y = d;
		}
		for(auto it: g[u])
		{
			if(!vis[it])
				Q.push({it, d+1});
		}
	}

	cout<<fpath.size()+y-1<<endl<<p.first<<" "<<q.first<<" "<<x<<endl;

	return 0;
}
