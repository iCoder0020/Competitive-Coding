/*
ID: iCoder0020
PROG: The Child and Toy
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long int

using namespace std;

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int V[N+1];
	vector<int> adj_list[N+1];
	int l,r;
	for(int n = 1; n<=N; n++)
		cin>>V[n];
	for(int m = 0; m<M; m++)
	{
		cin>>l>>r;
		adj_list[l].push_back(r);
		adj_list[r].push_back(l);
	}
	set <int> visited;
	int ans = 0;
	for(int i = 0; i<N; i++)
	{
		int sum = 0;
		int min_sum = INT_MAX;
		int node;
		for(int j = 1; j<=N && (visited.find(j) == visited.end()); j++)
		{
			sum = 0;
			for(auto it: adj_list[j])
			{
				sum += it;
			}
			if(sum < min_sum)
			{
				min_sum = sum;
				node = j;
			}
		}
		visited.insert(node);
		ans += min_sum;
		adj_list[node].clear();
		for(auto it: adj_list[node])
		{
			auto it2 = find(adj_list[it].begin(), adj_list[it].end(), node);
			adj_list[it].erase(it2);
		}
	}
	return 0;
}
