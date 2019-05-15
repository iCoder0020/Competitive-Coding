/*
ID: iCoder0020
PROG: Sereja and Suffixes
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
	int ans[N];
	set <int> S;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int n = N-1; n>=0; n--)
	{
		S.insert(A[n]);
		ans[n] = S.size();
	}
	while(M--)
	{
		int ind;
		cin>>ind;
		cout<<ans[ind-1]<<endl;
	}
	return 0;
}