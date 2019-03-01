/*
ID: ishan_sang
PROG: PNTWLL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N,M;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		long long int H[N];
		long long int C[N];
		bool C_occured[M];
		for(int m = 0; m<M; m++)
		{
			C_occured[m] = false;
		}
		for(int n = 0; n<N; n++)
		{
			cin>>H[n];
		}
		for(int n = 0; n<N; n++)
		{
			cin>>C[n];
		}
		long long int max_height = H[N-1];
		C_occured[C[N-1]-1] = true;
		int count = 1;
		for(int n = N-2; n>=0; n--)
		{
			if(H[n]>max_height)
			{
				if(C_occured[C[n]-1] == false)
				{
					count++;
					C_occured[C[n]-1] = true;
				}
				max_height = H[n];
			}
		}		
		cout<<count<<"\n";
	}
	return 0;
}