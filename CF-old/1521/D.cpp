#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>>g;
vector<vector<int>>ans;
set<int> dianodes;
bool done;
int topnode;

void farthest_helper(int u, vector<bool>&vis, int d, pair<int,int>&ans)
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
		farthest_helper(v, vis, d+1, ans);
	}
}

pair<int, int> farthest_node(int u)
{
	pair<int, int> ans = {u, 0};
	vector<bool>vis(g.size(), false);
	farthest_helper(u, vis, 0, ans);
	return ans;
}

void get_path_helper(int a, int b, vector<bool>&vis)
{
	if(done)
		return;
	if(a == b)
	{
		done = true;
		dianodes.insert(b);
		return;
	}
	if(vis[a])
		return;
	vis[a] = true;
	dianodes.insert(a);
	for(auto v: g[a])
		get_path_helper(v, b, vis);
	if(!done)
		dianodes.erase(a);
}

void get_path(int a, int b)
{
	vector<bool>vis(g.size(),  false);
	get_path_helper(a, b, vis);
}

void final_dfs(int u, vector<bool>&vis)
{
	if(vis[u])
		return;
	vis[u] = true;
	for(auto v: g[u])
	{
		if(dianodes.find(v) != dianodes.end())
			continue;
		if(vis[v])
			continue;
		if(u != topnode)
			ans.push_back({u, v, topnode, v});
		topnode = v;
		final_dfs(v, vis);
	}
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		dianodes.clear();
		g.clear();
		ans.clear();
		g.resize(N+1);
		done = false;
		for(int n = 0; n<N-1; n++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		pair<int, int>p1 = farthest_node(1);
		pair<int, int>p2 = farthest_node(p1.first);
		int a = p1.first, b = p2.first;
		topnode = a;
		get_path(a, b);
		vector<bool>checked(g.size(), false);
		for(int u: dianodes)
			final_dfs(u, checked);
		cout<<ans.size()<<endl;
		for(auto it: ans)
		{
			for(auto jt: it)
				cout<<jt<<" ";
			cout<<endl;
		}
	}
	return 0;
}
