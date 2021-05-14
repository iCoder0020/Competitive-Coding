// https://codeforces.com/contest/461/problem/B

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int N;
vector<vector<int>>g;
vector<int>colour;
vector<vector<int>>aux;

int power(int a, int b)
{
	int ans = 0;
	if(a == 1 || b == 0)
		return 1;
	int c = power(a,b/2);
	if(b&1)
		ans = (a*((c*c)%MOD))%MOD;
	else
		ans = (c*c)%MOD;
	return ans;
}

int invmod(int a)
{
	return power(a, MOD-2);
}

int mul(vector<int> v)
{
	int p = 1;
	for(auto it: v)
	{
		it = it%MOD;
		p = (p*it)%MOD;
	}
	return p;
}

void dfs(int node)
{
	int x = 1;
	for(auto child: g[node])
		dfs(child);
	for(auto child: g[node])
		x = mul({x,aux[child][0]+aux[child][1]});
	if(colour[node] == 0)
	{
		aux[node][0] = x;
		aux[node][1] = 0;
		for(auto child: g[node])
			aux[node][1] = (aux[node][1] + mul({aux[child][1],x,invmod(aux[child][0]+aux[child][1])}))%MOD;
	}
	else
	{
		aux[node][0] = 0;
		aux[node][1] = x;
	}	
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N;
	g.resize(N);
	colour.resize(N);
	aux.resize(N, vector<int>(2,0));
	for(int n = 1; n<N; n++)
	{
		int p;
		cin>>p;
		g[p].push_back(n);
	}
	for(int n = 0; n<N; n++)
		cin>>colour[n];
	dfs(0);
	cout<<aux[0][1]<<endl;
	return 0;
}