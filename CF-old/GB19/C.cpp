#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		int S = 0, X = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			S += A[n];
			X ^= A[n];
		}
		vector<int>v;
		if(S != 2*X)
		{
			v.push_back(X);
			v.push_back(S+X);
		}
		cout<<v.size()<<endl;
		for(auto it: v)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
