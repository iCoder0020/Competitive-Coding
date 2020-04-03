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
	int A[N], X = 0;
	for(int n = 0; n<N; n++)
	{
		A[n] = B[n]+X;
		X = max(X, A[n]);
	}
	for(int n = 0; n<N; n++)
		cout<<A[n]<<" ";
	cout<<endl;
	return 0;
}
