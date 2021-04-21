#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18

void gib(int X, int Y, int f, int N, vector<int>&v)
{
	int cnt = N;
	for(int i = X; i<=Y; i+=f)
	{
		v.push_back(i);
		cnt--;
		if(cnt<0)
			break;
	}
	int p = X-f;
	while(cnt>0 && p>0)
	{
		v.push_back(p);
		cnt--;
		p-=f;
	}
	p = Y+f;
	while(cnt>0)
	{
		v.push_back(p);
		cnt--;
		p+=f;
	}
	if(cnt<0 || v.size()!=N)
	{
		v.clear();
		v.push_back(INF);
	}
	sort(v.begin(),v.end(),greater<int>());
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int X,Y;
		cin>>X>>Y;
		int diff = Y-X;
		set<int>factors;
		for(int i = 1; i<=diff; i++)
			if(diff%i == 0)
				factors.insert(i);
		int max_val = INF, max_factor = -1;
		vector<int>v;
		for(int factor: factors)
		{
			gib(X,Y,factor,N,v);
			if(v[0]<max_val)
			{
				max_factor = factor;
				max_val = v[0];
			}
			v.clear();
		}
		gib(X,Y,max_factor,N,v);
		for(auto it: v)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}