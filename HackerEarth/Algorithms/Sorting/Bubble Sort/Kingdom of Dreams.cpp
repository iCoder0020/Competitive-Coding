/*
ID: icoder_0020
PROG: Kingdom of Dreams
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		li A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		sort(A, A+N);
		li ans = 0;
		while(N > 3)
		{
			ans += min(2*A[0] + A[N-1] + A[N-2], A[0] + 2*A[1] + A[N-1]);
			N -= 2;
		}
		if(N == 3)
		{
			ans += A[0] + A[1] + A[2];
		}
		else if(N == 2)
		{
			ans += A[1];
		}
		else
		{
			ans += A[0];
		}
		cout<<ans<<endl;
	}
	return 0;
}