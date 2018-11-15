/*
ID: ishan_sang
PROG: LEDGER
LANG: C++
*/
 
#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		
		long long int A[N];
		long long int A_sum[N] = {0};
		int i = -1;
		int j = -1;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n == 0)
			{
				A_sum[n] = A[n];
			}
			else
			{
				A_sum[n] = A[n] + A_sum[n-1];
			}
		}
		if(N == 1)
		{
			cout<<"1"<<" "<<"1"<<"\n";
		}
		else
		{
			int A_rem[N];
			int A_rem_count[N] = {0};
			int A_rem_index[N];
			int i_min = 0;
			int j_min = N+1;
			for(int n = 0; n<N; n++)
			{
				A_rem[n] = A_sum[n]%N;
				if(A_rem[n] == 0)
				{
					i = 0;
					j = n+1;
					if(j-i < j_min-i_min)
					{
						i_min = i;
						j_min = j;
					}
				}
				if(A_rem_count[A_rem[n]] == 0)
				{
					A_rem_count[A_rem[n]]++;
					
					A_rem_index[A_rem[n]] = n+1;
				}
				else
				{
					i = A_rem_index[A_rem[n]];
					j = n+1;
					if(j-i < j_min-i_min)
					{
						i_min = i;
						j_min = j;
					}
					A_rem_index[A_rem[n]] = n+1;
				}
			}
			cout<<i_min+1<<" "<<j_min<<"\n";
		}
	}
}
 