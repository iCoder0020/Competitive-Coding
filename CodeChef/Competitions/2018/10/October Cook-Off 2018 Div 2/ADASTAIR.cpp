/*
ID: ishan_sang
PROG: ADASTAIR
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
		int N,K;
		int stair_count = 0;
		int current = 0;
		cin>>N>>K;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		for(int n = 0; n<N; n++)
		{
			if(A[n] - current > K)
			{
				while(A[n]-current > K)
				{
					stair_count++;
					current += K;
				}
				if(A[n] - current <= K)
				{
					current = A[n];
				}
			}
			else
			{
				current = A[n];
			}
		}
		cout<<stair_count<<"\n";
	}
	return 0;
}