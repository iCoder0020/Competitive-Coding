#include <bits/stdc++.h>

using namespace std;

#define int long long

int N,M;
vector<vector<int>>g;
vector<int>colour;
bool poss = true;

void dfs(int i, int c)
{
	if(colour[i] != -1)
	{
		if(colour[i] != c)
			poss = false;
		return;
	}
	colour[i] = c;
	for(auto it: g[i])
		dfs(it, c^1);
}

int32_t main()
{
	cin>>N>>M;
	g.resize(N+1);
	colour.resize(N+1, -1);
	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int n = 1; n<=N; n++)
		if(colour[n] == -1)
			dfs(n, 0);
	vector<int>v0;
	vector<int>v1;
	for(int n = 1; n<=N; n++)
	{
		if(colour[n] == -1)
			poss = false;
		else if(colour[n] == 0)
			v0.push_back(n);
		else
			v1.push_back(n);
	}
	if(!poss)
		cout<<-1<<endl;
	else
	{
		cout<<v0.size()<<endl;
		for(auto it: v0)
			cout<<it<<" ";
		cout<<endl;
		cout<<v1.size()<<endl;
		for(auto it: v1)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
