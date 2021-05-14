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
		string S;
		cin>>S;
		vector<vector<int>>g(N+1), revg(N+1);
		for(int n = 1; n<=N; n++)
		{
			int v;
			if(S[n-1] == 'L')
				v = (n-2+N)%N+1;
			else
				v = n%N+1;
			g[n].push_back(v);
			revg[v].push_back(n);
		}
		for(int n = 1; n<=N; n++)
		{
			cout<<n<<" points to "<<g[n][0]<<" and is pointed to by: ";
			for(auto it: revg[n])
				cout<<it<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}