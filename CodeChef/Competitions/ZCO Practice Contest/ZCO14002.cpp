/*
ID: ishan_sang
PROG: ZCO14002
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int lli;

lli minimum(lli a, lli b, lli c)
{
	if(a<b && a<c)
	{
		return a;
	}
	else
	{
		return min(b,c);
	}
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	lli dp[N];
	lli min_dp;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int n = 0; n<N; n++)
	{
		dp[n] = A[n];
		if(n>=3)
		{
			dp[n] += minimum(dp[n-1], dp[n-2], dp[n-3]);
			if(n == 3)
			{
				min_dp = dp[n];
			}
		}
	}
	cout<<minimum(dp[N-1], dp[N-2], dp[N-3])<<"\n";
	return 0;
}