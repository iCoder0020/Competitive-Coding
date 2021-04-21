#include <bits/stdc++.h>

using namespace std;

#define int long long

#define MOD 998244353 

int32_t main()
{
	int N;
	cin>>N;
	vector<int> pow10(N+1,1);
	for(int n = 1; n<=N; n++)
		pow10[n] = (pow10[n-1]*10)%MOD;
	vector<int> dp(N+1);
	dp[N] = 10;
	for(int i = 1; i<N; i++)
	{
		dp[i] = (2*9*pow10[N-i])%MOD;
		if(N-i-2 >= 0)
			dp[i] = (dp[i] + ((N-i-1)*81*pow10[N-i-1])%MOD)%MOD;
	}
	for(int i = 1; i<=N; i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return 0;
}
