#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N, X;
		cin>>N>>X;
		int W[N];
		for(int n = 0; n<N; n++)
			cin>>W[n];
		int prefix[N];
		sort(W, W+N);
		prefix[0] = W[0];
		for(int n = 1; n<N; n++)
			prefix[n] = prefix[n-1]+W[n];
		if(prefix[N-1] == X)
			cout<<"NO"<<endl;
		else
		{
			for(int n = 0; n<N; n++)
			{
				if(prefix[n] == X)
				{
					int x = W[n];
					W[n] = W[N-1];
					W[N-1] = x;
				}
			}
			cout<<"YES"<<endl;
			for(int n = 0; n<N; n++)
				cout<<W[n]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
