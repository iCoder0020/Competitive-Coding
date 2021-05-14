#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 100000000

int32_t main()
{
	int N, M, A, B;
	cin>>N>>M>>A>>B;
	int DP[N+1][M+1][A+1][B+1];
	for(int i = 0; i<=N; i++)
		for(int j = 0; j<=M; j++)
			for(int a = 0; a<=A; a++)
				for(int b = 0; b<=B; b++)
					DP[i][j][a][b] = 0; 
	for(int i = 1; i<=min(A,N); i++)
		DP[i][0][i][0] = 1;
	for(int j = 1; j<=min(B,M); j++)
		DP[0][j][0][j] = 1;
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=M; j++)
		{
			for(int a = 1; a<=A; a++)
				for(int b = 0; b<=B; b++)
					DP[i][j][a][0] = (DP[i][j][a][0] + DP[i-1][j][a-1][b])%MOD;
			for(int b = 1; b<=B; b++)
				for(int a = 0; a<=A; a++)
					DP[i][j][0][b] = (DP[i][j][0][b] + DP[i][j-1][a][b-1])%MOD;
		}
	}
	int ans = 0;
	for(int a = 0; a<=A; a++)
		for(int b = 0; b<=B; b++)
			ans = (ans + DP[N][M][a][b])%MOD;
	cout<<ans<<endl;
	return 0;
}
