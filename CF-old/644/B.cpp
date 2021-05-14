#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A, A+N);
		int x = A[N-1];
		for(int n = 1; n<N; n++)
			x = min(x, A[n]-A[n-1]);
		cout<<x<<endl;
	}
	return 0;
}
