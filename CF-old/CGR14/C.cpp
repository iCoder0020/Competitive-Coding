#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M,X;
		cin>>N>>M>>X;
		vector<pair<int,int>>A(N);
		for(int n = 0; n<N; n++)
		{
			cin>>A[n].first;
			A[n].second = n;
		}
		sort(A.begin(), A.end());
		cout<<"YES"<<endl;
		int B[N];
		for(int n = 0; n<N; n++)
		{
			int k = n%M + 1;
			B[A[n].second] = k;
		}
		for(int n = 0; n<N; n++)
			cout<<B[n]<<" ";
		cout<<endl;
	}
	return 0;
}