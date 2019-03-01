/*
ID: icoder_0020
PROG: Equal Array
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
		int A[N];
		long long int prefix_sum[N] = {0};
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n>0)
			{
				prefix_sum[n] = prefix_sum[n-1];
			}
			prefix_sum[n] += A[n];
		}
		long long int min = prefix_sum[N-1] - 2*prefix_sum[0];
		for(int n = 0; n<N; n++)
		{
			long long int temp = prefix_sum[N-1] - 2*prefix_sum[n];
			if(temp >= 0)
			{
				min = (min<temp)?min:temp;
			}
		}
		if(min < 0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<min<<endl;
		}
	}
}