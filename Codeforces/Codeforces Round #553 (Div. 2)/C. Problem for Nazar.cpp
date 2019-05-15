/*
ID: iCoder0020
PROG: Problem for Nazar
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

int32_t main()
{
	pair<pair<int,int>,int>arr[61];
	int total_count[61] = {0};
	int pow_2[61];
	pow_2[0] = 1;
	for(int n = 1; n<61; n++)
		pow_2[n] = 2*pow_2[n-1];
	arr[0] = {{1, 1}, 1};
	total_count[0] = 1;
	int odd = 3;
	int even = 2;
	int idx = 0;
	int in1, in2;
	int ans = 0;
	for(int i = 1; i<=60; i++)
	{
		if(i%2)
		{
			arr[i] = {{even, even + 2*(pow_2[i]-1)}, pow_2[i]};
			even += 2*(pow_2[i]-1) + 2;
		}
		else
		{
			arr[i] = {{odd, odd + 2*(pow_2[i]-1)}, pow_2[i]};
			odd += 2*(pow_2[i]-1) + 2;
		}
		total_count[i] = total_count[i-1] + arr[i].second;
	}
	int L,R;
	cin>>L>>R;
	if(L == 1 && R == 1)
		ans = 1;
	else
	{
		for(int i = 0; i<61; i++)
		{
			if(total_count[i]>=L)
			{
				in1 = i;
				break;
			}
		}
		for(int i = in1; i<61; i++)
		{
			if(total_count[i]>=R)
			{
				in2 = i;
				break;
			}
		}
		if(in1 == in2)
		{
			int n = R-L+1;
			int a = arr[in1].first.first + 2*(L-total_count[in1-1]-1);
			ans = ((n%MOD)*((a+n-1)%MOD))%MOD;
		}
		else
		{
			for(int i = in1; i<=in2; i++)
			{
				if(i == 0)
				{
					ans = 1;
				}
				else if(i == in1)
				{
					int n = total_count[i]-L+1;
					int a = arr[i].first.first + 2*(L-total_count[i-1]-1);
					ans = ((n%MOD)*((a+n-1)%MOD))%MOD;
				}
				else if(i == in2)
				{
					int n = R-total_count[i-1];
					int a = arr[i].first.first;
					ans = (ans + ((n%MOD)*((a+n-1)%MOD))%MOD)%MOD;
				}
				else
				{
					int n = total_count[i] - total_count[i-1];
					int a = arr[i].first.first;
					ans = (ans + ((n%MOD)*((a+n-1)%MOD))%MOD)%MOD;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}