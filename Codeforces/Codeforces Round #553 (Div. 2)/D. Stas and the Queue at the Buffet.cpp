/*
ID: iCoder0020
PROG: Stas and the Queue at the Buffet
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int B[N];
	int C[N];
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n]>>B[n];
		C[n] = A[n]-B[n];
		sum += B[n]*N - A[n];
	}
	sort(C, C+N, greater<int>());
	for(int n = 1; n<=N; n++)
	{
		sum += n*C[n-1];
	}
	cout<<sum<<endl;
	return 0;
}