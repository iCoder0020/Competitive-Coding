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
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		vector<bool>peak(N,false);
		for(int n = 1; n<N-1; n++)
			if(A[n] > A[n-1] && A[n] > A[n+1])
				peak[n] = true;
		int l = 0, cnt = 0, max_cnt = 0;
		for(int n = 1; n<K; n++)	
		{
			if(peak[n-1])
				cnt++;
			if(max_cnt < cnt)
				max_cnt = cnt;
		}
		for(int n = K; n<N; n++)
		{
			if(peak[n-K+1])
				cnt--;
			if(peak[n-1])
				cnt++;
			if(max_cnt < cnt)
			{
				l = n-K+1;
				max_cnt = cnt;
			}
		}
		cout<<max_cnt+1<<" "<<l+1<<endl;
	}
	return 0;
}
