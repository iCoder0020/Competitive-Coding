#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	vector<int> A(N);
	vector<vector<int>> g(32);
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int n = 0; n<N; n++)
	{
		for(int i = 0; i<32; i++)
			if(A[n]&(1<<i))
				g[i].push_back(n);
	}
	vector<int>B;
	set<int>S;
	for(int n = 31; n>=0; n--)
	{
		if(g[n].size() == 1)
		{
			B.push_back(A[g[n][0]]);
			S.insert(g[n][0]);
			break;
		}
	}
	for(int n = 0; n<N; n++)
		if(S.find(n) == S.end())
			B.push_back(A[n]);
	for(auto it: B)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}
