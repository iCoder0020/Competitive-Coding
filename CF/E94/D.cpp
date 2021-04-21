#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		map<int,int>cnt[N+1];
		int A[N+1];
		for(int n = 1; n<=N; n++)
		{
			cin>>A[n];
			cnt[n][A[n]]++;
			for(auto it: cnt[n-1])
				cnt[n][it.first] += cnt[n-1][it.first];
		}
		int ans = 0;
		for(int k = N-1; k>=3; k--)
		{
			for(int j = k-1; j>=2; j--)
			{	
				int lc = cnt[N][A[j]]-cnt[k][A[j]];
				int ic = cnt[j-1][A[k]];
				ans += ic*lc;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
