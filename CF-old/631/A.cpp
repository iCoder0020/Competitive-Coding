#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		int A[N];
		vector<bool>vis(N+K+1, false);
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			vis[A[n]] = true;
		}
		int X = K;
		int n;
		for(n = 1; n<=N+K; n++)
		{
			if(!vis[n])
			{
				if(X == 0)
				{
					// cout<<n-1<<endl;
					break;
				}
				else
				{
					X--;
				}
			}
		}
		cout<<n-1<<endl;
	}
	return 0;
}
