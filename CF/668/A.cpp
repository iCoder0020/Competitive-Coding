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
		for(int n = N-1; n>=0; n--)
			cout<<A[n]<<" ";
		cout<<endl;
	}
	return 0;
}
