/*
ID: ishan_sang
PROG: XDCOMP
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 1000000007

using namespace std;

int main()
{
	int N, X;
	cin>>N>>X;
	int A[N+1];
	int u,v;
	li count = 0;
	vector <int> adj_list[N+1]; 
	for(int n = 1; n<=N; n++)
	{
		cin>>A[n];
	}
	for(int n = 0; n<N-1; n++)
	{
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	return 0;
}