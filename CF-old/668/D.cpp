#include <bits/stdc++.h>

using namespace std;

#define int long long

void fill_dist(vector<vector<int>>&g, vector<int>&dist, vector<bool>&vis, int u, int d)
{
	if(vis[u])
		return;
	vis[u] = true;
	dist[u] = d;
	for(int v: g[u])
		fill_dist(g,dist,vis,v,d+1);
}

pair<int,int> farthest_node(vector<vector<int>>&g, vector<bool>&vis, int u)
{
	if(vis[u])
		return {-1,-1};
	vis[u] = true;
	pair<int,int> ans = {u,0};
	for(int v: g[u])
	{
		pair<int,int> temp = farthest_node(g,vis,v);
		if(ans.second<temp.second+1)
			ans = {temp.first, temp.second+1};
	}
	return ans;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,A,B,X,Y;
		cin>>N>>A>>B>>X>>Y;
		vector<vector<int>>g(N+1);
		for(int n = 0; n<N-1; n++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<bool>vis(N+1, false);
		vector<int>dist(N+1, 0);
		fill_dist(g,dist,vis,B,0);
		vis.assign(N+1,false);
		int a = farthest_node(g,vis,B).first;
		vis.assign(N+1,false);
		int diameter = farthest_node(g,vis,a).second;
		if(dist[A] <= X || 2*X >= diameter)
			cout<<"Alice";
		else if(2*X < Y)
			cout<<"Bob";
		else
			cout<<"Alice";
		cout<<endl;
	}
	return 0;
}