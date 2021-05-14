#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M,K;
	cin>>N>>M>>K;

	int A[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];

	map<pair<int,int>, int> rules;
	for(int i = 0; i<K; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		rules[{a-1,b-1}] = c;
	}

	//dp[i][j] = last element is i, j is mask for current dish selection
	vector<vector<int>> dp(N, vector<int>(1LL<<N, 0));
	
	vector<vector<int>> v(N+1); 
	for(int i = 0; i<(1LL<<N); i++)
	{
		int cnt = __builtin_popcount(i);
		v[cnt].push_back(i);
	}

	int maxm = 0;

	for(int i = 1; i<=N; i++)
	{
		for(int x: v[i])
		{
			for(int j = 0; j<N; j++)
			{
				if((1LL<<j) & x)
				{
					dp[j][x] = A[j];
					for(int k = 0; k<N; k++)
					{
						if(k == j)
							continue;
						if((1<<k) & x)
							dp[j][x] = max(dp[j][x], dp[k][x^(1<<j)] + A[j] + rules[{k,j}]);
					}
					if(i == M)
						maxm = max(maxm, dp[j][x]);
					// cout<<j<<", "<<x<<": "<<dp[j][x]<<endl;
				}
			}
		}
	}

	cout<<maxm<<endl;	

	return 0;
}
