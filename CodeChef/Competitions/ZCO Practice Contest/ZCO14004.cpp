/*
ID: ishan_sang
PROG: ZCO14004
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int lli;

lli max(lli a, lli b, lli c)
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
	lli dp[N][3];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	if(N <= 2)
	{
		lli sum = 0;
		for(int n = 0; n<N; n++)
		{
			sum += A[n];
		}
		cout<<sum<<endl;
	}
	else
	{
		dp[N-1][0] = 0;
		dp[N-1][1] = A[N-1];
		dp[N-1][2] = A[N-1];

		dp[N-2][0] = A[N-1];
		dp[N-2][1] = A[N-2];
		dp[N-2][2] = A[N-1] + A[N-2];

		dp[N-3][0] = A[N-1] + A[N-2];
		dp[N-3][1] = A[N-1] + A[N-3];
		dp[N-3][2] = A[N-2] + A[N-3];

		for(int n = N-4; n>=0; n--)
		{
			dp[n][0] = max(dp[n+1][0], dp[n+1][1], dp[n+1][2]);
			dp[n][1] = max(dp[n+2][0], dp[n+2][1], dp[n+2][2]) + A[n];
			dp[n][2] = max(dp[n+3][0], dp[n+3][1], dp[n+3][2]) + A[n] + A[n+1];
		}
		cout<<max(max(dp[0][0], dp[0][1], dp[0][2]),max(dp[1][0], dp[1][1], dp[1][2]),max(dp[2][0], dp[2][1], dp[2][2]))<<endl;
	}
	return 0;
}