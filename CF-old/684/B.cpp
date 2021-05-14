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
		int A[N*K];
		for(int i = 0; i<N*K; i++)
			cin>>A[i];
		sort(A, A+N*K, greater<int>());
		int p = (N+1)/2;
		int total = (N-p)*K;
		int sum = 0;
		int cnt = 0;
		// cout<<N-p<<endl;
		for(int i = N-p; cnt<K; i+=N-p+1)
			sum += A[i], cnt++;
		cout<<sum<<endl;
	}
	return 0;
}
