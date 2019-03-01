/*
ID: ishan_sang
PROG: SLAEL
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
	int T;
	cin>>T;
	lli N,K;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		lli A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		int count_gt_K = 0;
		int index = 0;
		int length = 0;
		int max_length = 0;
		for(int n = 0; n<N; n++)
		{
			if(A[n]>K)
			{
				if(count_gt_K == 0)
				{
					count_gt_K = 1;
					index = n;
					length++;
				}
				else 
				{
					if(A[n] != A[index])
					{
						max_length = max(max_length, length);
						length = length - 1;
						index = n;
					}
					length++;
				}
			}
			else
			{
				length++;
			}
		}
		cout<<max(max_length,length)<<"\n";
	}
	return 0;
}