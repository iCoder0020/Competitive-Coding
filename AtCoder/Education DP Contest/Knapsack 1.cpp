/*
ID: iCoder0020
PROG: Knapsack 1
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define w(n) info[n].first
#define v(n) info[n].second

int32_t main()
{
	int N,W;
	cin>>N>>W;
	vector<int>dp(W+1, 0);
	pair<int, int> info[N];
	for(int n = 0; n<N; n++)
	{
		cin>>w(n)>>v(n);
		for(int j = W-w(n); j>=0; j--)
			dp[w(n)+j] = max(dp[w(n)+j], v(n) + dp[j]);
	}
	cout<<dp[W]<<endl;
	return 0;	
}