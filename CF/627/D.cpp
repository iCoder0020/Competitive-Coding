#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N], B[N], C[N];
	vector<int>v;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int n = 0; n<N; n++)
		cin>>B[n];
	int cnt = 0;
	for(int n = 0; n<N; n++)
		C[n] = A[n]-B[n];
	sort(C, C+N);
	for(int n = 0; n<N; n++)
	{
		int i = lower_bound(C+n+1, C+N, -C[n]+1) - C;
		cnt += N - i;
	}
	cout<<cnt<<endl;
	return 0;
}
