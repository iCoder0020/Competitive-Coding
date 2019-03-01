/*
ID: ishan_sang
PROG: AGECAL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	li T;
	cin>>T;
	for(li t = 0; t<T; t++)
	{
		li N;
		cin>>N;
		li A[N];
		li sum[N];
		li year_length = 0;
		li leap_years = 0;
		for(li n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n == 0)
			{
				sum[n] = A[n];
			}
			else
			{
				sum[n] = sum[n-1] + A[n];
			}
			year_length += A[n];
		}
		li YB, MB, DB;
		cin>>YB>>MB>>DB;
		li YC, MC, DC;
		cin>>YC>>MC>>DC;
		for(int n = YB; n<=YC; n++)
		{
			if(n%4 == 0)
			{
				leap_years++;
			}
		}
		li years = (YC-YB+1);
		li age = (years-leap_years)*year_length + leap_years*(year_length+1);
		if(MB!=1)
		{
			age -= sum[MB-2];
		}
		age-=(DB-1);
		if(MC!=N)
		{
			age -= (year_length-sum[MC-1]);
		}
		if(YC%4 == 0) 
		{
			age--;
		}
		age -= (A[MC-1] - DC);
		cout<<age<<endl;
	}
	return 0;
}