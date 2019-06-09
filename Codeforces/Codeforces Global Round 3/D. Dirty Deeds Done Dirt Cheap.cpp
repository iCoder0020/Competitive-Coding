/*
ID: iCoder0020
PROG: Dirty Deeds Done Dirt Cheap
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

bool mysort1(pair<pair<int,int>,int> &A, pair<pair<int,int>,int> &B)
{
	return A.first.second > B.first.second;
}
bool mysort2(pair<pair<int,int>,int> &A, pair<pair<int,int>,int> &B)
{
	return A.first.second < B.first.second;
}

int32_t main()
{
	int N;
	cin>>N;
	vector<pair<pair<int,int>,int>> t1;
	vector<pair<pair<int,int>,int>> t2;	
	for(int n = 0; n<N; n++)
	{
		int u,v;
		cin>>u>>v;
		if(u<v)
			t1.push_back({{u,v},n+1});
		else
			t2.push_back({{u,v}, n+1});
	}
	sort(t1.begin(), t1.end(), mysort1);
	sort(t2.begin(), t2.end(), mysort2);

	vector<int>ans1;
	vector<int>ans2;

	int a,b;

	b = INT_MAX;

	for(auto it: t1)
	{
		if(it.first.first < b)
		{
			a = it.first.first;
			b = it.first.second;
			ans1.push_back(it.second);
		}
	}

	b = 0;

	for(auto it: t2)
	{
		if(it.first.first > b)
		{
			a = it.first.first;
			b = it.first.second;
			ans2.push_back(it.second);
		}
	}

	if(ans1.size() < ans2.size())
	{
		cout<<ans2.size()<<endl;
		for(auto it: ans2)
			cout<<it<<" ";
		cout<<endl;
	}
	else
	{
		cout<<ans1.size()<<endl;
		for(auto it: ans1)
			cout<<it<<" ";
		cout<<endl;
	}

	return 0;
}