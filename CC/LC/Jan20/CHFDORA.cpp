#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		int A[N][M];
		for(int n = 0; n<N; n++)
			for(int m = 0; m<M; m++)
				cin>>A[n][m];
		int ans = N*M;
		for(int n = 1; n<N-1; n++)
		{
			for(int m = 1; m<M-1; m++)
			{
				int v = 0, h = 0;
				for(int i = 1; ; i++)
				{
					if(n+i>=N || n-i < 0)
						break;
					if(A[n+i][m] != A[n-i][m])
						break;
					v = i;
				}
				for(int j = 1; ; j++)
				{
					if(m+j>=M || m-j < 0)
						break;
					if(A[n][m+j] != A[n][m-j])
						break;
					h = j;
				}
				ans += min(v,h);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}