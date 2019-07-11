/*
ID: icoder_0020
PROG: ADASEA
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int sz;
int N,M;

int dfs(vector<vector<char>> &g, vector<vector<bool>> &vis, pair<int,int> pos)
{
	int x = pos.first;
	int y = pos.second;
	if(vis[x][y])
		return 0;
	sz++;
	vis[x][y] = true;
	if(x+1<N && g[x+1][y] == '#')
		dfs(g, vis, {x+1,y});
	if(y+1<M && g[x][y+1] == '#')
		dfs(g, vis, {x,y+1});
	if(x-1>=0 && g[x-1][y] == '#')
		dfs(g, vis, {x-1,y});
	if(y-1>=0 && g[x][y-1] == '#')
		dfs(g, vis, {x,y-1});
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		vector<vector<char>>g(N, vector<char>(M));
		vector<vector<bool>>vis(N, vector<bool>(M));
		int num = 0;
		int den = N*M;
		for(int i = 0; i<N; i++)
			for(int j = 0; j<M; j++)
				cin>>g[i][j];
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				sz = 0;
				if(g[i][j] == '#' && !vis[i][j])
				{
					dfs(g, vis, {i,j});
					num += sz*sz;
				}
			}
		}
		if(num == 0)
			cout<<"0";
		else
		{
			int gcd = __gcd(num,den);
			num/=gcd;
			den/=gcd;
			if(den == 1)
				cout<<num;
			else
				cout<<num<<" / "<<den;
		}
		cout<<endl;
	}
	return 0;
}