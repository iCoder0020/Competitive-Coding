/*
ID: ishan_sang
PROG: DPAIRS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin>>N>>M;
	int A[N], B[M];
	int minA_index = 0;
	int maxB_index = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] < A[minA_index])
		{
			minA_index = n;
		}
	}
	for(int m = 0; m<M; m++)
	{
		cin>>B[m];
		if(B[m] > B[maxB_index])
		{
			maxB_index = m;
		}
	}
	for(int m = 0; m<M; m++)
	{
		cout<<minA_index<<" "<<m<<endl;
	}
	for(int n = 0; n<N; n++)
	{
		if(n != minA_index)
		{
			cout<<n<<" "<<maxB_index<<endl;
		}
	}
	return 0;
}