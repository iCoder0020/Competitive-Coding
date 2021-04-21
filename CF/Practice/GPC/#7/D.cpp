#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
vector<vector<char>>g;
vector<vector<set<int>>>vis;
int N,M,R,C,X,Y;
 
void dfs(int x, int y, int l, int r)
{
	if(x<0 || y<0 || x>=N || y>=M || l>X || r>Y || g[x][y] == '*')
		return;
	if(vis[x][y].find(l)==vis[x][y].end())
		vis[x][y]
	vis[x][y].insert({l,r});
	dfs(x-1,y,l,r);
	dfs(x+1,y,l,r);
	dfs(x,y-1,l+1,r);
	dfs(x,y+1,l,r+1);
}
 
int32_t main()
{
	cin>>N>>M;
	cin>>R>>C;
	cin>>X>>Y;
	g.resize(N, vector<char>(M));
	vis.resize(N, vector<set<pair<int,int>>>(M));
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>g[n][m];
	X = min(X,2*M);
	Y = min(Y,2*M);
	dfs(R-1,C-1,0,0);
	int ans = 0;
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			if(vis[n][m].size())
				// cout<<"+";
				ans++;
			// else
			// 	cout<<".";
		}
		// cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}