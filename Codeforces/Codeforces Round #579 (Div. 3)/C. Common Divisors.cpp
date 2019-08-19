/*
ID: iCoder0020
PROG: Common Divisors
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int gcd;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
			gcd = A[n];
		else
			gcd = __gcd(A[n], gcd);
	}
	int cnt = 0;
	for(int i = 1; i<=sqrt(gcd); i++)
	{
		if(gcd%i == 0)
		{
			if(gcd/i == i)
				cnt++;
			else
				cnt += 2;
		}
	}
	cout<<cnt<<endl;
	return 0; 
}