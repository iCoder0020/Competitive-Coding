#include <bits/stdc++.h>

using namespace std;

#define int long long

void check(vector<vector<char>>&g, vector<vector<bool>>&vis, int x, int y, int N, int M)
{
	if(x>=N || y>=M || x<0 || y<0|| g[x][y] == '#' || vis[x][y] == true)
		return;
	vis[x][y] = true;
	check(g, vis, x-1, y, N, M);
	check(g, vis, x, y+1, N, M);
	check(g, vis, x, y-1, N, M);
	check(g, vis, x+1, y, N, M); 
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		vector<vector<char>>g(N, vector<char>(M));
		vector<pair<int,int>>good;
		vector<pair<int,int>>bad;
		vector<vector<bool>>vis(N, vector<bool>(M,false));
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				cin>>g[n][m];
				if(g[n][m] == 'B')
					bad.push_back({n,m});
				if(g[n][m] == 'G')
					good.push_back({n,m});
			}
		}
		for(auto it: bad)
		{
			int n = it.first;
			int m = it.second;
			if(n>0 && g[n-1][m]=='.')
				g[n-1][m] = '#';
			if(m>0 && g[n][m-1]=='.')
				g[n][m-1] = '#';
			if(n<N-1 && g[n+1][m]=='.')
				g[n+1][m] = '#';
			if(m<M-1 && g[n][m+1]=='.')
				g[n][m+1] = '#';
		}
		bool poss = true;
		check(g, vis, N-1, M-1, N, M);
		for(auto it: good)
		{
			if(!vis[it.first][it.second])
			{
				poss = false;
				break;
			}
		}
		for(auto it: bad)
		{
			if(vis[it.first][it.second])
			{
				poss = false;
				break;
			}	
		}
		if(poss)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}