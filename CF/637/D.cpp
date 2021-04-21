#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;
		cin>>N>>K;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		map<int,int>MAP0;
		map<int,int>MAP1;
		for(int n = 0; n<N/2; n++)
		{
			MAP0[A[n]+A[N-1-n]]++;
			MAP1[min(A[n], A[N-1-n])+1]++;
			MAP1[max(A[n], A[N-1-n])+K+1]--;
		}
		vector<int>v(2*K+2, 0);
		for(auto it: MAP1)
			v[it.first] += it.second;
		int min_ans = N/2;
		for(int i = 2; i<=2*K; i++)
		{
			v[i] += v[i-1];
			int z = MAP0[i];
			int o = v[i]-z;
			int t = N/2-o-z;
			min_ans = min(min_ans, o+2*t);
		}
		cout<<min_ans<<endl;
	}
	return 0;
}
