/*
ID: iCoder0020
PROG: Pashmak and Flowers
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int B[N];
	for(int n = 0; n<N; n++)
		cin>>B[n];
	sort(B, B+N);
	if(B[0] == B[N-1])
	{
		cout<<0<<" "<<((N*(N-1))/2)<<endl;
	}
	else
	{
		int m1 = upper_bound(B, B+N, B[0]) - B;
		int m2 = lower_bound(B, B+N, B[N-1]) - B;
		m2 = N-m2;
		cout<<B[N-1]-B[0]<<" "<<m1*m2<<endl;
	}
	return 0;
}