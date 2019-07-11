/*
ID: iCoder0020
PROG: Letters
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int A[N];
	int prefix[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
			prefix[n] = A[n];
		else
			prefix[n] = prefix[n-1]+A[n]; 
	}
	while(M--)
	{
		int temp;
		cin>>temp;
		int i = lower_bound(prefix, prefix+N, temp) - prefix;
		int j;
		if(i == 0)
			j = temp;
		else
			j = temp-prefix[i-1];
		cout<<i+1<<" "<<j<<endl;
	}
	return 0;
}