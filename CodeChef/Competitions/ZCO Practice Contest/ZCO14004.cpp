/*
ID: ishan_sang
PROG: ZCO14004
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int lli;

lli max(lli a, lli b)
{
	return (a>b)?a:b;
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	lli dp[N] = {0};
	for(int n = 0; n<N; n++)
	{
		dp[n] = -1;
	}
	int current_length;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	dp[0] = A[0];
	if(N == 1)
	{
		cout<<dp[0]<<endl;
	}
	else
	{
		dp[1] = A[0] + A[1];
		current_length = 2;
		for(int n = 2; n<N; n++)
		{
			if(dp[n] == -1)
			{
				dp[n] = A[n];
				if(dp[n-2] >= A[n-1])
				{
					dp[n] += dp[n-2];
					current_length = 1;
					if(n+1 < N)
					{
						dp[n+1] = A[n+1] + dp[n];
						current_length = 2;
					}
				}
				else
				{
					dp[n] += A[n-1];
					current_length = 2;
				}
			}
		}
		for(int n = 0; n<N; n++)
		{
			cout<<n<<": "<<dp[n]<<endl;
		}
		cout<<max(dp[N-1], dp[N-2])<<endl;
	}
	return 0;
}