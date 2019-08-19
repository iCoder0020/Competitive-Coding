/*
ID: iCoder0020
PROG: Almost Equal
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	if(N%2 == 0)
		cout<<"NO";
	else
	{
		cout<<"YES\n";
		int A[2*N];
		A[0] = 1;
		A[2*N-1] = 2*N;
		A[N] = 2;
		for(int n = 1; n<2*N; n++)
		{
			if(n == N)
				continue;
			if(n%2 == 1)
				A[n] = A[n-1]+3;
			else
				A[n] = A[n-1]+1;
		}
		for(int n = 0; n<2*N; n++)
			cout<<A[n]<<" ";
		// for(int n = 0; n<2*N; n++)
		// {
		// 	int sum = 0;
		// 	for(int m = n; m<n+N; m++)
		// 		sum += A[m%(2*N)];
		// 	cout<<sum<<endl;
		// }
	}
	cout<<endl;
}