#include <bits/stdc++.h>

using namespace std;

#define int long long

int N,M;
vector<vector<char>>g;
vector<vector<int>>vis;
bool cycle;

void dfs(int i, int j, char c)
{
	if(i<0 || i>=N || j<0 || j>=M || g[i][j]!=c)
		return;
	if(vis[i][j] == 1)
		return;
	if(vis[i][j] == 2)
	{
		cycle = true;
		return;
	}
	vis[i][j] = 1;
	dfs(i+1, j, c);
	dfs(i, j+1, c);
	dfs(i-1, j, c);
	dfs(i, j-1, c);
	vis[i][j] = 2;
}

int32_t main()
{
	cin>>N>>M;
	cycle = false;
	g.resize(N, vector<char>(M));
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>g[n][m];
	vis.resize(N,vector<int>(M,0));
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			if(vis[n][m] == 0)
				dfs(n,m,g[n][m]);
	if(cycle)
		cout<<"Yes";
	else
		cout<<"No";
	cout<<endl;
	return 0;
}
