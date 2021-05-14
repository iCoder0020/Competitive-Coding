#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 998244353

int power(int a, int b)
{
	if(a == 1 || b == 0)
		return 1;
	if(b == 1)
		return a;
	int c = power(a, b/2);
	int d = (c*c)%MOD;
	if(b&1)
		return (d*a)%MOD;
	else
		return d;
}

int inv_mod(int a)
{
	return power(a, MOD-2);
}

int get_answer(int num, int den)
{
	return (num*inv_mod(den))%MOD;
}

pair<int,int> normalise(pair<int,int> p, pair<int,int> q)
{
	int x = (q.second*p.first + q.first*p.second)%MOD;
	int y = (p.second*q.second)%MOD;
	return {x,y};
} 

int32_t main()
{
	int N;
	cin>>N;
	int K[N];
	vector<vector<int>>items(N);
	unordered_map<int,int>MAP;
	for(int n = 0; n<N; n++)
	{
		cin>>K[n];
		for(int m = 0; m<K[n]; m++)
		{
			int x;
			cin>>x;
			items[n].push_back(x);
			MAP[x]++;
		}
	}
	int num[N], den[N];
	pair<int,int> prob;
	for(int n = 0; n<N; n++)
	{
		num[n] = 0;
		den[n] = K[n];
		for(int m = 0; m<K[n]; m++)
			num[n] += MAP[items[n][m]];
		if(n == 0)
			prob = {num[n], den[n]};
		else
			prob = normalise(prob, {num[n], den[n]});
	}
	prob.second = (((prob.second*N)%MOD)*N)%MOD;
	cout<<get_answer(prob.first, prob.second)<<endl;
	return 0;
}

