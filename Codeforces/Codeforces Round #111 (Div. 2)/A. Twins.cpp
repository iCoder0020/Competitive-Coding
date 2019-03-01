/*
ID: iCoder0020
PROG: Twins
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		sum += A[n];
	}
	sort(A, A+N, greater<int>());
	int s = 0;
	int ans = N;
	for(int n = 0; n<N; n++)
	{
		s += A[n];
		if(s > sum-s)
		{
			ans = n+1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}