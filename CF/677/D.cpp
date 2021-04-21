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
		vector<pair<int,int>>A(N);
		for(int n = 0; n<N; n++)
		{
			int x;
			cin>>x;
			A[n] = {x, n+1};
		}
		sort(A.begin(), A.end());
		if(A[0].first == A[N-1].first)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			vector<pair<int,int>>edges;
			int f = A[0].first, s;
			for(int n = 0; n<N; n++)
			{
				if(A[n].first != f)
				{
					s = A[n].second;
					edges.push_back({A[0].second, A[n].second});
				}
			}
			for(int n = 1; n<N; n++)
			{
				if(A[n].first == f)
					edges.push_back({A[n].second, s});
			}
			for(auto it: edges)
				cout<<it.first<<" "<<it.second<<endl;
		}
	}		
	return 0;
}