#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int,int> parent;
map<int,int> sz;
int ans1, ans2;

void set_parent(int a)
{
	parent[a] = a;
	sz[a] = 1;
}

int find_parent(int a)
{
	while(a != parent[a])
	{
		parent[a] = parent[parent[a]];
		a = parent[a];
	}
	return a;
}

void set_union(int a, int b, int &x, int &y, int N)
{
	a = find_parent(a);
	b = find_parent(b);
	parent[a] = b;
	sz[b] += sz[a];
	sz[a] = 0;
	if(b!=N && sz[b] > y)
	{
		x = b;
		y = sz[b];
	}
	else
	{
		x = a;
		y = 1;
	}
}

bool poss(vector<int> &A, int N)
{
	for(int n = 0; n<=N; n++)
		set_parent(n);
	int x = A[0], y = 1;
	for(int n = 0; n<N; n++)
	{
		// for(auto it: sz)
		// 	cout<<it.first<<" "<<it.second<<endl;
		// cout<<"x: "<<x<<", "<<y<<endl;
		if(x != A[n])
			return false;
		set_union(A[n], A[n]+1, x, y, N);
		if(n+1 == N)
			break;
		if(y == 1)
			x = A[n+1];
	}
	return true;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<pair<int,int>>P(N);
		for(int n = 0; n<N; n++)
		{
			cin>>P[n].first;
			P[n].second = n;
		}
		sort(P.begin(), P.end());
		vector<int>idx(N);
		for(int n = 0; n<N; n++)
			idx[n] = P[n].second;
		sz.clear();
		parent.clear();
		if(poss(idx, N))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
