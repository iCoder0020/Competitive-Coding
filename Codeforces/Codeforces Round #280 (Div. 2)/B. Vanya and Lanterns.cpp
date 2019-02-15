/*
ID: iCoder0020
PROG: Vanya and Lanterns
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,L;
	cin>>N>>L;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	int max_diff = max(2*A[0], 2*(L - A[N-1]));
	for(int n = 1; n<N; n++)
	{
		max_diff = max(max_diff, A[n] - A[n-1]);
	}
	cout<<setprecision(8)<<fixed<<(double)(max_diff)/2.0<<endl;
	return 0;
}