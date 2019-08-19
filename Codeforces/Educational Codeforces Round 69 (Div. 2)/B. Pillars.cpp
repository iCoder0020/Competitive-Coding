/*
ID: iCoder0020
PROG: Pillars
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
	int prev, curr, next;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] == N)
			curr = n;
	}
	int cnt = N-1;
	prev = max((int)0, curr-1);
	next = min(N-1, curr+1);
	while(cnt>0)
	{
		if(A[prev] != cnt && A[next] != cnt)
			break;
		if(A[prev] == cnt)
		{
			prev = max((int)0, prev-1);
			cnt--;
		}
		if(A[next] == cnt)
		{
			next = min(N-1, next+1);
			cnt--;
		}
	}
	if(cnt == 0)
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}