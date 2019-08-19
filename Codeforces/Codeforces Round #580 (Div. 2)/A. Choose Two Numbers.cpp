/*
ID: iCoder0020
PROG: Choose Two Numbers
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
	for(int n = 0; n<N; n++)
		cin>>A[n];
	int M;
	cin>>M;
	int B[M];
	for(int m = 0; m<M; m++)
		cin>>B[m];
	sort(A, A+N);
	sort(B, B+M);
	cout<<A[N-1]<<" "<<B[M-1]<<endl;
}