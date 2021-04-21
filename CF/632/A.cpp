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
		vector<vector<char>>ans(N,vector<char>(M,'X'));
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				if(n == N-1 && m == M-1)
					ans[n][m] = 'W';
				else
					ans[n][m] = 'B';
				cout<<ans[n][m];
			}
			cout<<endl;
		}
	}
	return 0;
}
