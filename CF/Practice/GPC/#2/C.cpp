#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>

int N,M;
vector<int>D;
vector<vector<int>>g;

bool bs(int days)
{
	pii nothing = {-1,-1};
	vector<pii>end(M+1, nothing);
	for(int i = 1; i<=M; i++)
	{
		if(g[i].size() == 0)
			return false;
		int p = lower_bound(g[i].begin(), g[i].end(), days)- g[i].begin();
		if(p>=g[i].size() && g[i][p-1]<=days)
			end[i] = {g[i][p-1],i};
		else if(g[i][p] <= days)
			end[i] = {g[i][p],i};
		else if(p-1>=0)
			end[i] = {g[i][p-1],i};
		if(end[i] == nothing)
			return false;
	}
	sort(end.begin(), end.end());
	int x = 0;
	for(pii p: end)
	{
		if(p == nothing)
			continue;
		if(D[p.second]+x<p.first)
			x+=D[p.second]+1;
		else
			return false;
	}
	return true;
}

int32_t main()
{
	cin>>N>>M;
	D.resize(M+1);
	g.resize(M+1);
	for(int n = 1; n<=N; n++)
	{
		int x;
		cin>>x;
		if(x!=0)
			g[x].push_back(n);
	}
	for(int m = 1; m<=M; m++)
		cin>>D[m];
	int lo = 1, hi = N+1, mid;
	while(lo<hi)
	{
		int mid = lo + (hi-lo)/2;
		if(bs(mid))
			hi = mid;
		else
			lo = mid+1;
	}
	if(lo == N+1)
		cout<<-1<<endl;
	else
		cout<<lo<<endl;
	return 0;
}
