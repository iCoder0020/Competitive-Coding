#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,q;
		cin>>a>>b>>q;
		int c = min(a,b);
		int d = max(a,b);
		a = c;
		b = d;
		int g = __gcd(a,b);
		int l = (a*b)/g;
		int p = l;
		while(q--)
		{
			int L,R;
			cin>>L>>R;
			int ans = 0;
			int x = (L/p)*p;
			if(x<L)
			{
				ans += max(0LL,(min(R+1,x+b)-L));
				x+=p;
			}		
			// cout<<ans<<endl;
			ans += ((R-x)/p)*b;
			// cout<<ans<<endl;
			x += ((R-x)/p)*p;
			while(x<=R)
			{
				ans += min(R+1,x+b)-x;
				// cout<<x<<" "<<ans<<endl;
				x+=p;
			}
			// cout<<L<<" "<<R<<" "<<ans<<endl;
			cout<<(R-L+1)-ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}
