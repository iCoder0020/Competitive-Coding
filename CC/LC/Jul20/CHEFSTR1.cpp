#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		int cnt = 0;
		for(int n = 0; n<N; n++)
			cin>>A[n];
		for(int n = 1; n<N; n++)
			cnt += abs(A[n]-A[n-1])-1;
		cout<<cnt<<endl;
	}
	return 0;
}