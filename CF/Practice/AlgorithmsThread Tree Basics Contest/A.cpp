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
	cout<<3*p2.second<<endl;
	return 0;
}