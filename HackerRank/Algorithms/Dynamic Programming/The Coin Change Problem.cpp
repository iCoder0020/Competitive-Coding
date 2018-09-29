/*
ID: iCoder0020
PROG: The Coin Change Problem
LANG: C++                  
*/

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int lli;

using namespace std;

int N,M;
lli C[51];
lli dp[251][51];

lli DP(lli N, lli m)
{
	if(m == M)
	{
		if(N != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if(dp[N][m] != -1)
	{
		return dp[N][m];
	}
	dp[N][m] = 0;
	int count = 0;
	while(count*C[m]<=N)
	{

		dp[N][m] += DP(N-count*C[m],m+1);
		count++;
	}
	return dp[N][m];
}

int main()
{
	cin>>N>>M;
	for(int m = 0; m<M; m++)
	{
		cin>>C[m];
	}
	for(int n = 0; n<N+1; n++)
	{
		for(int m = 0; m<M; m++)
		{
			dp[n][m] = -1;
		}
	}
	sort(C, C+M);
	cout<<DP(N, 0)<<"\n";
	return 0;
}