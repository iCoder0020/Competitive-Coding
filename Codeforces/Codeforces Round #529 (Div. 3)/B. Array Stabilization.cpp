/*
ID: iCoder0020
PROG: Array Stabilization
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	cout<<min(A[N-2]-A[0], A[N-1]-A[1])<<endl;
	return 0;
}