/*
ID: iCoder0020
PROG: Ilya and a Colorful Walk
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
	int ans1 = 0;
	for(int n = N-1; n>=0; n--)
	{
		if(A[n] != A[0])
		{
			ans1 = n;
			break;
		}
	}
	int ans2 = 0;
	for(int n = 0; n<N; n++)
	{
		if(A[N-1] != A[n])
		{
			ans2 = N-n-1;
			break;
		}
	}
	cout<<max(ans1,ans2)<<endl;
	return 0;
}