/*
ID: iCoder0020
PROG: Plus from Picture
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int c = 0;
int N,M;
vector<vector<char>>A;
vector<vector<bool>>vis;


void dfs(int x, int y)
{
	if(vis[x][y])
		return;
	vis[x][y] = true;
	c++;
	if(x-1>=0 && A[x-1][y] == '*')
		dfs(x-1, y);
	if(x+1<N && A[x+1][y] == '*')
		dfs(x+1, y);
	if(y-1>=0 && A[x][y-1] == '*')
		dfs(x, y-1);
	if(y+1<M && A[x][y+1] == '*')
		dfs(x, y+1);
}
int32_t main()
{
	cin>>N>>M;
	bool possible = false;
	vis.clear();
	vis.resize(N, vector<bool>(M, false));
	A.clear();
	A.resize(N, vector<char>(M));
	int cnt = 0;
	pair<int,int> pos;
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>A[n][m];
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			if(A[n][m] == '*')
			{
				if(c == 0)
					dfs(n,m);
				cnt++;
				if(n>0 && m>0 && n<N-1 && m<M-1)
				{
					if(A[n-1][m] == '*' && A[n+1][m] == '*' && A[n][m+1] == '*' && A[n][m-1] == '*')
						pos = {n,m};
				}
			}
		}
	}
	if(c != cnt || c<5)
		cout<<"NO";
	else
	{
		int x = pos.first;
		int y = pos.second;
		int i,j;
		int x1 = 0,x2 = 0,x3 = 0,x4 = 0;
		i = x;
		for(j = y; j>=0; j--)
		{
			if(A[i][j] == '*')
				x1++;
			else
				break;
		}
		for(j = y; j<M; j++)
		{
			if(A[i][j] == '*')
				x2++;
			else
				break;
		}
		j = y;
		for(i = x; i>=0; i--)
		{
			if(A[i][j] == '*')
				x3++;
			else
				break;
		}
		for(i = x; i<N; i++)
		{
			if(A[i][j] == '*')
				x4++;
			else
				break;
		}
		if(x1>0 && x2>0 && x3>0 && x4>0 && x1+x2+x3+x4-3 == cnt)
			cout<<"YES";
		else
			cout<<"NO";
	}
	cout<<endl;
	return 0; 
}