/*
ID: iCoder0020
PROG: Reach Median
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int N,S,ans = 0;
	cin>>N>>S;
	long long int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	int starting_index;
	if(A[N/2] == S)
	{
		cout<<"0\n";
	}
	else if(A[N/2]<S)
	{
		for(int n = N/2; A[n]<S && n<N; n++)
		{
			ans += abs(A[n] - S);
		}
		cout<<ans<<"\n";
	}
	else
	{
		for(int n = N/2; A[n]>S && n>=0; n--)
		{
			ans += abs(A[n] - S);
		}
		cout<<ans<<"\n";
	}
	return 0;
}