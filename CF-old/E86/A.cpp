#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		int ans = 0;
		if(x*y>0)
		{
			int d = min(abs(x), abs(y));
			if(2*a > b)
			{
				ans += b*d;
				if(x<0)
					x+=d, y+=d;
				else
					x-=d, y-=d;
			}
		}
		ans += a*(abs(x)+abs(y)) ;
		cout<<ans<<endl;
	}
	return 0;
}
