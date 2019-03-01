/*
ID: iCoder0020
PROG: Tanya and Candies
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	li A[N];
	li total_sum = 0;
	li odd_sum[N] = {0};
	li even_sum[N] = {0};
	int odd_index = 0;
	int even_index = 0;
	int cnt = 0; 
	if(N == 1)
	{
		cout<<1<<endl;
	}
	else if(N == 2)
	{
		cout<<0<<endl;
	}
	else
	{
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n == 0)
			{
				odd_sum[odd_index] = A[n];
				odd_index++;
			}
			else if(n == 1)
			{
				even_sum[even_index] = A[n];
				even_index++;
			}
			else if(n%2 == 0)
			{
				odd_sum[odd_index] = odd_sum[odd_index-1] + A[n];
				odd_index++;
			}
			else
			{
				even_sum[even_index] = even_sum[even_index-1] + A[n];
				even_index++;
			}
			total_sum += A[n];
		}
		int O = odd_index;
		int E = even_index;
		li os,es;
		for(int n = 0; n<N; n++)
		{
			if(n%2 == 0)
			{
				os = odd_sum[n/2] + even_sum[E-1] - A[n];
				if(n > 0)
				{
					os -= even_sum[n/2 - 1];
				}
				if(2*os == total_sum - A[n])
				{
					cnt++;
				}
			}
			else
			{
				es = even_sum[n/2] + odd_sum[O-1] - A[n];
				if(n > 0)
				{
					es -= odd_sum[n/2];
				}
				if(2*es == total_sum - A[n])
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}