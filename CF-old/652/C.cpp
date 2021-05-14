#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;
		cin>>N>>K;
		int A[N], W[K];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		for(int k = 0; k<K; k++)
			cin>>W[k];
		sort(A, A+N, greater<int>());
		sort(W, W+K);
		vector<int>maxm(K, -1*INF), minm(K, INF), cnt(K,0);
		int n = 0;
		for(int k = 0; k<K; k++)
		{
			if(W[k]>2)
				break;
			maxm[k] = max(maxm[k], A[n]);
			minm[k] = min(minm[k], A[n]);
			cnt[k]++;
			n++;
		}
		while(n<N)
		{
			for(int k = 0; k<K; k++)
			{
				if(cnt[k] == W[k])
					continue;
				maxm[k] = max(maxm[k], A[n]);
				minm[k] = min(minm[k], A[n]);
				cnt[k]++;
				n++;
			}
		}
		int ans = 0;
		for(int k = 0; k<K; k++)
			ans += maxm[k]+minm[k];
		cout<<ans<<endl;
	}
	return 0;
}