/*
ID: iCoder0020
PROG: Coffee and Coursework (Easy version)
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

bool check(li A[], int N, int M, li days)
{
	li sum = 0;
	// cout<<days<<" ";
	for(int rem = 0; rem<=ceil(N/days); rem++)
	{
		for(int n = 0; n<days; n++)
		{	
			if(rem*days + n >= N)
			{
				// cout<<"all added: "<<sum<<endl;
				return false;
			}
			else
			{
				sum += A[rem*days + n] - rem;
				if(sum >= M)
				{
					// cout<<"got it: "<<sum<<endl;
					return true;
				}
			}
		}
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	li A[N];
	li sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		sum += A[n];
	}
	if(sum < M)
	{
		cout<<-1<<endl;
	}
	else if(sum == M)
	{
		cout<<N<<endl;
	}
	else
	{
		sort(A,A+N,greater<int>());
		li low = 1;
		li high = N;
		li days;
		while(1)
		{
			days = (low+high)/2;
			if(high - low <= 1)
			{
				if(check(A, N, M, low))
				{
					days = low;
				}
				else
				{
					days = high;
				}
				break;
			}
			else if(check(A, N, M, days))
			{
				high = days;
			}
			else
			{
				low = days + 1;
			}
		}
		cout<<days<<endl;
	}
	return 0;
}