#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N;
	cin>>N;
	vector<int>DP(N+1, 0);
	DP[0] = 1;
	for(int n = 1; n<=N; n++)
	{
		for(int m = 1; m<=6; m++)
		{
			if(n-m>=0)
				DP[n] = (DP[n]+DP[n-m])%MOD;
		}
	}
	cout<<DP[N]<<endl;
	return 0;
}
