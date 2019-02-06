/*
ID: ishan_sang
PROG: DEPCHEF
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		int D[N];
		for(int n = 0; n<N; n++)
		{
			cin>>D[n];
		}
		int max_value = -1;
		for(int n = 0; n<N; n++)
		{
			if(D[n] > A[(n-1+N)%N] + A[(n+1)%N] && max_value < D[n])
			{
				max_value = D[n];
			}
		}
		cout<<max_value<<endl;
	}
	return 0;
}