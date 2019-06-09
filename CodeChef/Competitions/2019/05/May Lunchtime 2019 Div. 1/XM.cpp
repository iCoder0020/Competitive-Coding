/*
ID: ishan_sang
PROG: XM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,Q;
		cin>>N>>Q;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int L,R;
		while(Q--)
		{
			cin>>L>>R;
			int sum = 0;
			for(int i = L-1; i<R; i++)
				sum += A[i]^(i-(L-1));
			cout<<sum<<endl;
		}
	}
    return 0;
}