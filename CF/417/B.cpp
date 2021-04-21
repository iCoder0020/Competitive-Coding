#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e10

int32_t main()
{
	int N,M;
	cin>>N>>M;
	string S[N+1];
	for(int n = 1; n<=N; n++)
		cin>>S[N-n+1];
	vector<int>A(N+1, 0), B(N+1, 0);
	vector<vector<int>>DP(N+1, vector<int>(2,0));
	int maxN = 0;
	for(int n = 1; n<=N; n++)
	{
		for(int m = 1; m<=M; m++)
		{
			if(S[n][m] == '1')
			{
				A[n] = M-m+1;
				break;
			}
		}
		for(int m = M; m>=1; m--)
		{
			if(S[n][m] == '1')
			{
				B[n] = m;
				break;
			}
		}
		if(A[n] != 0)
			maxN = n;
		// cout<<A[n]<<" "<<B[n]<<endl;
	}
	DP[maxN][0] = B[maxN];
	DP[maxN][1] = A[maxN];
	// cout<<DP[maxN][0]<<" "<<DP[maxN][1]<<endl;
	for(int n = maxN-1; n>=1; n--)
	{
		DP[n][0] = B[n] + min(B[n]+DP[n+1][0], M+1-B[n]+DP[n+1][1]) + 1;
		DP[n][1] = A[n] + min(A[n]+DP[n+1][1], M+1-A[n]+DP[n+1][0]) + 1;

		// cout<<DP[n][0]<<" "<<DP[n][1]<<endl;
	}
	cout<<DP[1][0]<<endl;
	return 0;
}
