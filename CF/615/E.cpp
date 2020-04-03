#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N, M;
	cin>>N>>M;
	int A[N][M];
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>A[n][m];
	int cycle_up[N];
	int total_ans = 0;
	for(int m = 0; m<M; m++)
	{
		for(int n = 0; n<N; n++)
		{
			int val = n*M+m+1;
			if(val == A[n][m])
				cycle_up[n] = 0;
			else if((A[n][m]-m-1)<0 || (A[n][m]-m-1)%M !=0 || A[n][m]<=0 || A[n][m] > N*M)
				cycle_up[n] = -1;
			else
			{
				int x = (A[n][m]-m-1)/M;
				if(x > n)
					cycle_up[n] = n-x+N;
				else
					cycle_up[n] = n-x;
			}
		}
		map<int, int> freq;
		for(int n = 0; n<N; n++)
			freq[cycle_up[n]]++;
		int maxm = 0, cycle_req;
		int ans = N;
		for(auto it: freq)
		{
			if(it.first < 0)
				continue;
			ans = min(ans, it.first+(N-it.second));
		}
		total_ans += ans;
	}	
	cout<<total_ans<<endl;
	return 0;
}
