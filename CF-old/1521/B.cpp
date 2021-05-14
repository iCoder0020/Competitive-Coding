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
		vector<vector<int>> v;
		for(int i = 1; i<N; i+=2)
		{
			int a = A[i-1], b = A[i];
			int c = min(a,b);
			int x = c;
			int y = 1000000007;
			v.push_back({i, i+1, x, y});
			A[i-1] = c, A[i] = y;
		}
		cout<<v.size()<<endl;
		for(auto it: v)
		{
			for(auto jt: it)
				cout<<jt<<" ";
			cout<<endl;
		}
	}
	return 0;
}
