/*
ID: iCoder0020
PROG: 507 - Jill Rides Again
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		li A[N-1];
		li sum = -1*INT_MAX;
		int s = -1;
		int e = -1;
		li max_sum = -1*INT_MAX;
		int max_s = -1;
		int max_e = -1;
		for(int n = 0; n<N-1; n++)
		{
			cin>>A[n];
			if(A[n] > sum+A[n])
			{
				s = n+1;
				e = n+2;
				sum = A[n];
			}
			else
			{
				e++;
				sum += A[n];
			}
			if(sum > max_sum)
			{
				max_sum = sum;
				max_s = s;
				max_e = e;
			}
			else if(sum == max_sum)
			{
				if(e - s > max_e - max_s)
				{
					max_s = s;
					max_e = e;
				}
			}
		}
		if(max_sum > 0)
		{
			cout<<"The nicest part of route "<<t+1<<" is between stops "<<max_s<<" and "<<max_e<<endl;
		}
		else
		{
			cout<<"Route "<<t+1<<" has no nice parts"<<endl;
		}
	}

	return 0;
}