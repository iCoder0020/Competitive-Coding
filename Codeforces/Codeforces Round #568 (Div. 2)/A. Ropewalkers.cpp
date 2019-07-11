/*
ID: iCoder0020
PROG: Ropewalkers
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int a[3],d;
	int ans = 0;
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a, a+3);
	if(a[1] - a[0] >= d)
	{
		if(a[2] - a[1] < d)
		{
			ans = d-(a[2] - a[1]);
		}
	}
	else
	{
		if(a[2] - a[1] >= d)
		{
			ans = d - (a[1] - a[0]);
		}
		else
		{
			if(a[2] - a[0] >= 2*d)
			{
				ans = min(abs(a[0]+d-a[1]), abs(a[1]+d-a[2]));
			}
			else
			{
				ans = a[0]+d - a[1] + a[1] + d -a[2]; 
			}
		}
	}
	cout<<ans<<endl;
	return 0; 
}