#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<int> dp(N+1, 1);
	for(int n = 3; n<=N; n++)
	{
		for(int i = n-1; i>=2; i--)
		{
			for(int j = 0; j<=n-i; j++)
			{
				dp[n] = (dp[n] + )%M;
			}
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}
