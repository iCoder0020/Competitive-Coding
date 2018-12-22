/*
ID: iCoder0020
PROG: Vasya and Book
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	int n,x,y,d;
	int ans1, ans2, ans3;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>n>>x>>y>>d;
		ans1 = -1;
		ans2 = -1;
		ans3 = -1;
		if(abs(y-x)%d == 0)
		{
			ans1 = (abs(y-x))/d;
		}
		if((n-y)%d == 0)
		{
			ans2 = (n-x)/d + (n-y)/d;
			if((n-x)%d!=0)
			{
				ans2++;
			}
		}
		if((y-1)%d == 0)
		{
			ans3 = (x-1)/d + (y-1)/d;
			if((x-1)%d!=0)
			{
				ans3++;
			}
		}
		if(ans1 == -1 && ans2 == -1 && ans3 == -1)
		{
			cout<<"-1\n";
		}
		else
		{
			if(ans1 == -1)
			{
				ans1 = INT_MAX;
			}
			if(ans2 == -1)
			{
				ans2 = INT_MAX;
			}
			if(ans3 == -1)
			{
				ans3 = INT_MAX;
			}
			cout<<min(min(ans1, ans2),ans3)<<endl;
		}
	}
	return 0;
}