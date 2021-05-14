#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;	
		cin>>N>>K;
		int ans = N;
		for(int n = 1; n*n<=N; n++)
		{
			if(N%n == 0)
			{
				if(n<=K)
					ans = min(ans,N/n);
				if(N/n<=K)
					ans = min(ans,n);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
