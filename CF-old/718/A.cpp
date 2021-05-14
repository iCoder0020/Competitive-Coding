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
		int ans = -1;
		if(N%2050 == 0)
		{
			ans = 0;
			int k = 2050*10e14;
			while(k)
			{
				if(N>=k)
				{
					ans += N/k;
					N = N - (k)*(N/k);
				}
				k/=10;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
