#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int l,r,m;
		cin>>l>>r>>m;
		int a,b,c;
		for(int i = l; i<=r; i++)
		{
			int x = m - (m/i)*i;
			int y = m - ((m/i) + 1)*i;
			if(x <= r-l && m/i>0)
			{
				a = i;
				b = x+l, c = l;
				break;
			}
			if(y >= l-r)
			{
				a = i;
				b = y+r, c =r;
				break;
			}
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
