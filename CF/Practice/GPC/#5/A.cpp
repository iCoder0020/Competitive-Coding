#include <bits/stdc++.h>

using namespace std;

// #define int long long

int32_t main()
{
	int N;
	cin>>N;
	vector<vector<set<pair<int,int>>>>g(N+1, vector<set<pair<int,int>>>(N+1));
	vector<vector<int>>gp(N+1, vector<int>(N+1));
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=N; j++)
		{
			int x;
			cin>>x;
			g[i][j].insert({x,i});
			gp[i][j] = x;
		}
	}
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=N; j++)
		{
			if(i==j)
				continue;
			g[i][j].insert({gp[i][j], i});
			for(int k = 1; k<=N; k++)
			{
				if(i == k || j == k)
					continue;
				g[i][j].insert({gp[i][k] + gp[k][j], k});
			}
		}
	}

	set<int>S;
	for(int r = 1; r<=N; r++)
	{
		int x;
		int sum = 0;
		for(int n = 1; n<=N; n++)
		{
			for(int m = 1; m<=N; m++)
			{
				if(n==m || S.find(n)!=S.end() || S.find(m)!=S.end())
					continue;
				set<pair<int,int>>::iterator it= g[n][m].begin();
				while(g[n][m].size()>0 && (S.find(it->second) != S.end()))
				{
					g[n][m].erase(it);
					it = g[n][m].begin();
				}
				if(g[n][m].size()!=0)
					sum += it->first;
			}
		}
		cin>>x;
		S.insert(x);
		cout<<sum<<" ";
	}
	cout<<endl;
	return 0;
}
