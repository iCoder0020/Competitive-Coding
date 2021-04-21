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
		int ans = 0;
		int extra = 0;
		for(int n = 0; n<N; n++)
		{
			int x;
			cin>>x;
			if(x>=0)
				extra += x;
			else
			{
				int p = min(0LL, x+extra);
				extra -= (p-x);
				x = p;
				ans -= x;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
