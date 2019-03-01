/*
ID: icoder_0020
PROG: Learning Graph
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
bool mysort(pair<int,int> a, pair<int,int> b)
{
	if(a.second == b.second)
	{
		return a.first > b.first;
	}
	else
	{
		return a.second > b.second;
	}
}

int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	vector<pair<int,int>>adj_list[N];
	int val[N];
	for(int n = 0; n<N; n++)
	{
		cin>>val[n];
	}
	int X,Y;
	for(int m = 0; m<M; m++)
	{
		cin>>X>>Y;
		adj_list[X-1].push_back(make_pair(Y-1, val[Y-1]));
		adj_list[Y-1].push_back(make_pair(X-1, val[X-1]));
	}
	for(int n = 0; n<N; n++)
	{
		sort(adj_list[n].begin(), adj_list[n].end(), mysort);
		if(adj_list[n].size() >= K)
		{
			cout<<adj_list[n][K-1].first + 1<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}