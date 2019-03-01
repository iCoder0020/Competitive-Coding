/*
ID: iCoder0020
PROG: Gravity Flip
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long li;

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
	for(int n = 0; n<N; n++)
	{
		cout<<A[n]<<" ";
	}
	cout<<endl;
	return 0;
}