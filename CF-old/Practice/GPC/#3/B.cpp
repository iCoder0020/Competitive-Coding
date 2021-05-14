#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,M;
	cin>>N>>M;
	vector<vector<int>>A(N,vector<int>(M));
	for(int n = 0; n<N; n++)
	{
		int s = 0;
		for(int m = 0; m<M; m++)
		{
			int x;
			cin>>x;
			s+=x;
			A[n][m] = s;
		}
	}
	vector<int>dp(M);
	vector<int>prevr(M);
	vector<int>prevl(M);
	dp = prevr = prevl = A[0];
	for(int n = 1; n<N; n++)
	{
		for(int m = 1; m<M; m++)
			prevl[m] = max(prevl[m], prevl[m-1]);
		for(int m = M-2; m>=0; m--)
			prevr[m] = max(prevr[m], prevr[m+1]);
		for(int m = 0; m<M; m++)
			dp[m] = -1*INF;
		for(int m = 0; m<M; m++)
		{
			if((n&1) && m+1<M)
				dp[m] = max(dp[m], A[n][m]+prevr[m+1]);
			else if(!(n&1) && m-1>=0)
				dp[m] = max(dp[m], A[n][m]+prevl[m-1]);
		}
		for(int m = 0; m<M; m++)
			prevl[m] = prevr[m] = dp[m];
	}
	cout<<*max_element(dp.begin(), dp.end())<<endl;
	return 0;
}
