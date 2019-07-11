/*
ID: iCoder0020
PROG: Connect
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

vector<vector<char>>grid;
vector<vector<bool>>vis;
vector<pair<int,int>>v1;
vector<pair<int,int>>v2;
int min_ans;
int N;
int r1,c1,r2,c2;
int u,v;

int dist(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void dfs(pair<int,int> pos, int r, int c, int t)
{
	int x = pos.first;
	int y = pos.second;
	if(vis[x][y])
		return;
	vis[x][y] = true;
	if(x+1 <= N && grid[x+1][y] == '0') 
		dfs({x+1,y}, r, c, t);
	else if(t == 1)
		v1.push_back({x,y});
	else
		v2.push_back({x,y});

	if(x-1 >= 1 && grid[x-1][y] == '0') 
		dfs({x-1,y}, r, c, t);
	else if(t == 1)
		v1.push_back({x,y});
	else
		v2.push_back({x,y});
	
	if(y+1 <= N && grid[x][y+1] == '0') 
		dfs({x,y+1}, r, c, t);
	else if(t == 1)
		v1.push_back({x,y});
	else
		v2.push_back({x,y});
	
	if(y-1 >= 1 && grid[x][y-1] == '0') 
		dfs({x,y-1}, r, c, t);
	else if(t == 1)
		v1.push_back({x,y});
	else
		v2.push_back({x,y});
	
}

int main()
{
	cin>>N;
	cin>>r1>>c1>>r2>>c2;
	
	grid.clear();
	grid.resize(N+1, vector<char>(N+1));
	vis.clear();
	vis.resize(N+1, vector<bool>(N+1, false));

	for(int n = 1; n<=N; n++)
		for(int m = 1; m<=N; m++)
			cin>>grid[n][m];

	min_ans = INT_MAX;
	dfs({r1,c1}, r2, c2, 1);

	min_ans = INT_MAX;
	dfs({r2,c2}, r1, c1, 2);
	
	for(int i = 0; i<v1.size(); i++)
		for(int j = 0; j<v2.size(); j++)
			min_ans = min(min_ans, dist(v1[i].first, v1[i].second, v2[j].first, v2[j].second));

	if(min_ans == INT_MAX)
		min_ans = 0;
	cout<<min_ans<<endl;
	return 0;
}