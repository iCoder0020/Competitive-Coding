/*
ID: icoder_0020
PROG: ABA12C
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		long long int A[K+1];
		long long int dp[K+1];
		for(int i = 1; i<=K; i++)
		{
			cin>>A[i];
			if(A[i] == -1)
			{
				A[i] = INT_MAX;
			}
		}
		dp[0] = 0;
		dp[1] = A[1];
		for(int k = 2; k<=K; k++)
		{
			dp[k] = INT_MAX;
			for(int l = 1; l<=k; l++)
			{
				if(A[l] + dp[k-l] <= dp[k])
				{
					dp[k] = A[l] + dp[k-l];
				}
			}
		}
		if(dp[K] == INT_MAX)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<dp[K]<<endl;
		}
	}
	return 0;
}