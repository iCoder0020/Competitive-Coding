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
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int minm = *min_element(A.begin(), A.end());
		int maxm = *max_element(A.begin(), A.end());
		for(int n = 0; n<N; n++)
			A[n] = maxm - A[n];
		if(K>1)
		{
			int S = maxm - minm;
			if(K%2 == 0)
			{
				for(int n = 0; n<N; n++)
				{
					A[n] = S-A[n];
				}
			}
		}
		for(int n = 0; n<N; n++)
			cout<<A[n]<<" ";
		cout<<endl;
	}
	return 0;
}
