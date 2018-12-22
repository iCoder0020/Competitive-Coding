/*
ID: icoder_0020
PROG: Rhezo and Prime Problems
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
long long int maxm(long long int a, long long int b, long long int c)
{
	if(a>b && a>c)
	{
		return a;
	}
	else if(b>c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	int prime[N+1] = {0};
	vector<int> primes;

	for(int n = 2; n<=N; n++)
	{
		for(int m = 2; m<n; m++)
		{
			if(n%m == 0)
			{
				break;
			}
			else
			{
				if(m == n-1)
				{
					prime[n] = 1;
				}
			}
		}
		if(n == 2 || prime[n] == 1)
		{
			primes.push_back(n);
		}
	}

	long long int sum[N];

	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
		{
			sum[n] = A[n];
		}
		else
		{
			sum[n] = sum[n-1] + A[n];
		}
	}

	long long int dp[N] = {0};


	for(int n = N-2; n>=0; n--)
	{
		for(int m = 0; m<primes.size(); m++)
		{
			if(n + primes[m] -1 >= N)
			{
				dp[n] = maxm(dp[n], dp[n+1], 0);
				break;
			}
			else
			{ 
				if(n+primes[m]+1<N)
				{
					dp[n] = maxm(dp[n], dp[n+1], sum[n+primes[m]-1] - sum[n] + A[n] + dp[n+primes[m]+1]);
				}
				else
				{
					dp[n] = maxm(dp[n], dp[n+1], sum[n+primes[m]-1] - sum[n] + A[n]);
				}
			}
		}
	}
	cout<<dp[0]<<endl;
	return 0;
}