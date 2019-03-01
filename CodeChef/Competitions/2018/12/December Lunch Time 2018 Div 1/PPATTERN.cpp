/*
ID: ishan_sang
PROG: PPATTERN
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
		int A[N][N];
		int B[2*(N-1)];
		int count = 1;
		for(int i = 0; i<N-1; i++)
		{
			B[i] = count;
			count++;
		}
		count--;
		for(int i = N-1; i<2*(N-1); i++)
		{
			B[i] = count;
			count--;
		}
		for(int n = 0; n<N; n++)
		{
			A[n][0] = ((n+1)*(n+2))/2;
		}
		int k = 0;
		for(int i = 0; i<N; i++)
		{
			for(int j = 1; j<N; j++)
			{
				A[i][j] = A[i][j-1] + B[(k+i+j-1)%((2*(N-1)))];
			}
		}
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}