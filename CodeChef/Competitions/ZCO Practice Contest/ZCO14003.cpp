/*
ID: ishan_sang
PROG: ZCO14003
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli maximum(lli a, lli b)
{
	return (a>b)?a:b;
}

int main()
{
	int N;
	cin>>N;
	lli A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	lli max = 0;
	for(int n = 0; n<N; n++)
	{
		max = maximum((A[n]*(N-n)), max);
	}
	cout<<max<<endl;
	return 0;
}