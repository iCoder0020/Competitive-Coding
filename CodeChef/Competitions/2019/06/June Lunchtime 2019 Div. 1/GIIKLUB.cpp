/*
ID: ishan_sang
PROG: GIIKLUB
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>>g;

int N,X;		
int cnt;

void f(int x, int y, int sum)
{
	if(sum > X)
		return;
	if(x == N-1 && y == N-1)
		cnt++;
	if(x+1 < N)
		f(x+1, y, sum + g[x+1][y]);
	if(y+1 < N)
		f(x, y+1, sum + g[x][y+1]);
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>X;
		g.clear();
		g.resize(N, vector<int>(N, 0));
		cnt = 0;
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				cin>>g[i][j];
		f(0, 0, g[0][0]);
		cout<<cnt<<endl;	
	}
    return 0;
}