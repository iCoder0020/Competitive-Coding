#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,u,v;
		cin>>N>>u>>v;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int maxm = 0;
		for(int n = 1; n<N; n++)
			maxm = max(maxm, abs(A[n]-A[n-1]));
		int ans = 0;
		if(maxm == 0)
			ans = min({u+v, 2*v});
		else if(maxm == 1)
			ans = min(u,v);
		cout<<ans<<endl;
	}
	return 0;
}
