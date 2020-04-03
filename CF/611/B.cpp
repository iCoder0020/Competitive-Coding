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
		int a = N/K;
		int b = ceil((double)N/K);
		int maxm = K/2;
		int ans = min(a*K + maxm*(b-a), N);
		cout<<ans<<endl;
	}
	return 0;
}
