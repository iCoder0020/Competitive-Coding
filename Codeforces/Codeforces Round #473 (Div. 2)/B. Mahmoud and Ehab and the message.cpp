/*
ID: iCoder0020
PROG: Mahmoud and Ehab and the message
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<string>words;
vector<int>cost;
vector<int>rep;

void init(int N)
{
	words.clear();
	words.resize(N);
	cost.clear();
	cost.resize(N);
	rep.clear();
	rep.resize(N);
}

void make_set(int x)
{
	rep[x] = x;
}

int find_set(int x)
{
	while(x != rep[x])
	{
		rep[x] = rep[rep[x]];
		x = rep[x];
	}
	return x;
}

void union_set(int x, int y)
{
	int a = find_set(x);
	int b = find_set(y);

	if(a != b)
	{
		if(cost[a] < cost[b])
			rep[b] = a;
		else
			rep[a] = b;
	}
}

int32_t main()
{
	int N,K,M;
	cin>>N>>K>>M;
	init(N);
	map<string,int>MAP;
	for(int n = 0; n<N; n++)
	{
		cin>>words[n];
		MAP[words[n]] = n;
	}
	for(int n = 0; n<N; n++)
		cin>>cost[n];
	for(int n = 0; n<N; n++)
		make_set(n);
	for(int k = 0; k<K; k++)
	{
		int cnt;
		cin>>cnt;
		int f;
		cin>>f;
		for(int c = 1; c<cnt; c++)
		{
			int n;
			cin>>n;
			union_set(f-1, n-1);
		}
	}
	int tcost = 0;
	for(int m = 0; m<M; m++)
	{
		string str;
		cin>>str;
		tcost += cost[find_set(MAP[str])];
	}
	cout<<tcost<<endl;
	return 0;
}