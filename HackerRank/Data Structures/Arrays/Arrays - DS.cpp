/*
ID: iCoder0020
PROG: Arrays - DS
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
	for(int n = N-1; n>=0; n--)
	{
		cout<<A[n]<<" ";
	}
	cout<<endl;
	return 0;
}