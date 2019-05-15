/*
ID: ishan_sang
PROG: ADAKNG
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb(x) push_back(x)

int bfs(int r, int c, int K)
{
	int N = 8;
	int cnt = 0;
	bool visited[N][N];
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			visited[i][j] = false;

	queue <pair<pair<int,int>,int>> Q;
	Q.push({{r-1, c-1},0});
	visited[r-1][c-1] = true;
	while(!Q.empty())
	{
		pair<pair<int,int>,int>p = Q.front();
		int x = p.first.first;
		int y = p.first.second;
		int z = p.second;

		if(x-1 >= 0 && !visited[x-1][y])
		{
			Q.push({{x-1,y},z+1});
			visited[x-1][y] = true;
		}

		if(y-1 >= 0 && !visited[x][y-1])
		{
			Q.push({{x,y-1},z+1});
			visited[x][y-1] = true;
		}

		if(x-1 >= 0 && y-1>= 0 && !visited[x-1][y-1])
		{
			Q.push({{x-1,y-1},z+1});
			visited[x-1][y-1] = true;
		}

		if(x-1 >= 0 && y+1<N && !visited[x-1][y+1])
		{
			Q.push({{x-1,y+1},z+1});
			visited[x-1][y+1] = true;
		}

		if(x+1 < N && !visited[x+1][y])
		{
			Q.push({{x+1,y},z+1});
			visited[x+1][y] = true;
		}

		if(y+1 < N && !visited[x][y+1])
		{
			Q.push({{x,y+1},z+1});
			visited[x][y+1] = true;
		}

		if(x+1 < N && y-1 >= 0 && !visited[x+1][y-1])
		{
			Q.push({{x+1,y-1},z+1});
			visited[x+1][y-1] = true;
		}

		if(x+1 < N && y+1 < N && !visited[x+1][y+1])
		{
			Q.push({{x+1,y+1},z+1});
			visited[x+1][y+1] = true;
		}

		if(z <= K)
			cnt++;
		Q.pop();
	}
	return cnt;
}

int32_t main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int R,C,K;
		cin>>R>>C>>K;
		cout<<bfs(R,C,K)<<endl;
	}
	return 0;
}