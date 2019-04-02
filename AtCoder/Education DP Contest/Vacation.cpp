/*
ID: iCoder0020
PROG: Vacation
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int N;
	cin>>N;
	li A[N];
	li B[N];
	li C[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n]>>B[n]>>C[n];
	}
	li dp[N][3];
	
	dp[N-1][0] = A[N-1];
	dp[N-1][1] = B[N-1];
	dp[N-1][2] = C[N-1];

	for(int n = 2; n<=N; n++)
	{
		dp[N-n][0] = max(dp[N-n+1][1], dp[N-n+1][2]) + A[N-n];
		dp[N-n][1] = max(dp[N-n+1][0], dp[N-n+1][2]) + B[N-n];
		dp[N-n][2] = max(dp[N-n+1][0], dp[N-n+1][1]) + C[N-n];
	}

	li ans = max(dp[0][0], dp[0][1]);
	ans = max(ans, dp[0][2]);

	cout<<ans<<endl;

	return 0;	
}