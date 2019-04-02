/*
ID: iCoder0020
PROG: Little Girl and Maximum Sum
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	int A[N];
	int B[N+1] = {0};
	int L,R;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A, A+N);
	for(int q = 0; q<Q; q++)
	{
		cin>>L>>R;
		B[L-1]++;
		B[R]--;
	}
	for(int n = 1; n<N; n++)
	{
		B[n] += B[n-1];
	}
	sort(B, B+N);

	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		sum += A[n]*B[n];
	}
	cout<<sum<<endl;
	return 0;
}