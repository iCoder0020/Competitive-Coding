/*
ID: icoder_0020
PROG: ASSIGN
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<vector<int>>A;
vector<vector<int>>D;
int N;
int dp(int i, int bmask)
{
	if(i == N)
	{
		if(bmask == ((1<<N)-1))
			return 1;
		else
			return 0;
	}
	else
	{
		int ans = 0;
		for(int m = 1; m<=N; m++)
		{
			if(A[i][m] == 1)
				ans += dp(i+1, bmask|(1<<m));
		}
		return ans;
	}
}
int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		A.resize(N+1, vector<int>(N+1, -1));
		dp.resize(N+1, )
		for(int i = 1; i<=N; i++)
			for(int j = 1; j<=N; j++)
				cin>>A[i][j];
		

	}
	return 0;
}