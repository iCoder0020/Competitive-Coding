/*
ID: iCoder0020
PROG: Born This Way
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N, M, Ta, Tb, K;
	cin>>N>>M>>Ta>>Tb>>K;
	int A[N], B[M];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int m = 0; m<M; m++)
		cin>>B[m];
	bool possible = true;
	if(K >= N || K >= M)
		possible = false;

	int min_time = 0;

	for(int n = 0; n<=K; n++)
	{
		int i = lower_bound(B, B+M, A[n] + Ta) - B;
		if(i+(K-n) >= M)
			possible = false;
		else
		{
			// cout<<B[i+(K-n)]+Tb<<endl;
			min_time = max(min_time, B[i+(K-n)] + Tb);
		}
	}

	if(!possible)	
		cout<<-1<<endl;
	else
		cout<<min_time<<endl;
	return 0;
}