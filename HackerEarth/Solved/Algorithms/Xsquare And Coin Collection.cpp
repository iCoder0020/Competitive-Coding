/*
ID: icoder_0020
PROG: Xsquare And Coin Collection
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N,K;
		cin>>N>>K;
		int H[N];
		long long int dp[N] = {0};
		long long int max = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>H[n];
		}
		for(int n = 0; n<N; n++)
		{
			if(H[n]<=K)
			{
				if(n == 0)
				{
					dp[n] = H[n];
				}
				else
				{
					dp[n] = dp[n-1] + H[n];
				}
			}
			else
			{
				dp[n] = 0;
			}
			max = (max>dp[n])?max:dp[n];
		}
		cout<<max<<endl;
	}
	return 0;
}