#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M,K;
	cin>>N>>M>>K;
	int C[N+1];
	for(int n = 1; n<=N; n++)
		cin>>C[n];
	vector<vector<int>>ex(N+1, vector<int>(N+1, 0));
	for(int k = 0; k<K; k++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		ex[x][y] = c;
	}
	
	return 0;
}
