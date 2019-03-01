/*
ID: ishan_sang
PROG: XORIER
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_ODD 500000
#define MAX_EVEN 500000

int main()
{
	int T;
	cin>>T;
	int N;
	long int ans;
	int num;
	int max_odd;
	int max_even;
	int odd[MAX_ODD];
	int even[MAX_EVEN];
	int sum_odd[MAX_ODD];
	int sum_even[MAX_EVEN];
	for(int t = 0; t<T; t++)
	{
		ans = 0;
		max_odd = 0;
		max_even = 0;
		cin>>N;
		for(int n = 0; n<MAX_ODD; n++)
		{
			odd[n] = 0;
			sum_odd[n] = 0;
		}
		for(int n = 0; n<MAX_EVEN; n++)
		{
			even[n] = 0;
			sum_even[n] = 0;
		}
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num%2 == 0)
			{
				max_even = (max_even>num)?max_even:num;
				even[(num-2)/2]++;
			}
			else
			{
				max_odd = (max_odd>num)?max_odd:num;
				odd[(num-1)/2]++;
			}
		}
		for(int n = 0; n<=((max_odd-1)/2); n++)
		{
			if(n>=1)
			{
				sum_odd[n] = sum_odd[n-1];
			}
			sum_odd[n] += odd[n];
		}
		for(int n = 0; n<=((max_even-2)/2); n++)
		{
			if(n>=1)
			{
				sum_even[n] = sum_even[n-1];
			}
			sum_even[n] += even[n];
		}
		for(int n = 0; n<((max_odd-1)/2); n++)
		{
			if(((2*n+1)^(2*n+3)) > 2)
			{
				ans += odd[n]*odd[n+1];
			}
			if(n<(max_odd-1)/2-1)
			{
				ans += odd[n]*(sum_odd[(max_odd-1)/2]-sum_odd[n+1]);
			}
		}
		for(int n = 0; n<((max_even-2)/2); n++)
		{
			if(((2*n+2)^(2*n+4)) > 2)
			{
				ans += even[n]*even[n+1];
			}
			if(n<(max_even-2)/2-1)
			{
				ans += even[n]*(sum_even[(max_even-2)/2]-sum_even[n+1]);
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}