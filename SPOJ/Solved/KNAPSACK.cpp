/*
ID: icoder_0020
PROG: KNAPSACK
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
	cin>>W>>N;
	vector<vector<int>> dp(N, vector<int>(W+1, 0));
	vector<pair<int, int>> info(N);
	for(int n = 0; n<N; n++)
		cin>>w(n)>>v(n);
	for(int i = 0; i<=W; i++)
		if(w(0) <= i)
			dp[0][i] = v(0);
	for(int i = 0; i<N; i++)
		dp[i][0] = 0;
	for(int i = 1; i<N; i++)
	{
		for(int j = 1; j<=W; j++)
		{
			if(j>=w(i))
				dp[i][j] = max(v(i) + dp[i-1][max((int)0,j-w(i))], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[N-1][W]<<endl;
	return 0;	
}