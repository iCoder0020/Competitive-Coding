/*
ID: iCoder0020
PROG: Lunar New Year and Number Division
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	long long int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	long long int s = 0;
	for(int n = 0; n<N/2; n++)
	{
		s += (A[n] + A[N-n-1]) * (A[n] + A[N-n-1]);
	}
	cout<<s<<endl;
	return 0;
}