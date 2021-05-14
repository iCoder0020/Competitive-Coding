#include <bits/stdc++.h>

using namespace std;

#define int long long

bool is_perm(vector<int>&v)
{
	int N = v.size();
	vector<bool>vis(N+1, false);
	for(auto it: v)
	{
		if(it > N)
			return false;
		vis[it] = true;
	}
	for(int n = 1; n<=N; n++)
		if(!vis[n])
			return false;
	return true;
}

pair<pair<int,int>,pair<int,int>> res(vector<int>&A, int N, int x)
{
	int i,j;
	set<int>S;
	for(i = 0; i<N-1; i++)
	{
		if(S.find(A[i]) == S.end())
			S.insert(A[i]);
		else
			break;
	}
	vector<int>v1, v2;
	for(j = 0; j<N; j++)
	{
		if(j<i)
			v1.push_back(A[j]);
		else
			v2.push_back(A[j]);
	}
	pair<pair<int,int>,pair<int,int>> p,q;
	if(x == 0)
		p = {{0, i-1}, {i, N-1}};
	else
		p = {{0, N-i-1}, {N-i, N-1}};
	q = {{-1, -1}, {-1,-1}};
	return (is_perm(v1) && is_perm(v2))?p:q;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		pair<pair<int,int>,pair<int,int>>p;
		vector<pair<pair<int,int>,pair<int,int>>>ans;
		p = res(A, N, 0);
		if(p.first.first != -1)
			ans.push_back(p);
		reverse(A.begin(), A.end());
		p = res(A, N, 1);
		if(p.first.first != -1)
			ans.push_back(p);
		int x = ans.size();
		if(x == 2)
		{
			// for(int i = 0; i<x; i++)
			// 	cout<<ans[i].first.first<<" "<<ans[i].first.second<<"->"<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
			if(ans[0].first == ans[1].first)
				x--;
		}
		cout<<x<<endl;
		for(int i = 0; i<x; i++)
			cout<<(ans[i].first.second-ans[i].first.first+1)<<" "<<(ans[i].second.second-ans[i].second.first+1)<<endl;
		
	}
	return 0;
}
