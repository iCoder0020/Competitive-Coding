#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int ans = 0;
		while(N>=10)
		{
			ans += (N/10)*10;
			N = N - (N/10)*9;
		}
		ans += N;
		cout<<ans<<endl;
	}
	return 0;
}
