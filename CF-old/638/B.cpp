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
		int A[N];
		set<int>S;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			S.insert(A[n]);
		}
		if(S.size()>K)
			cout<<-1<<endl;
		else
		{
			if(S.size()<K)
			{
				for(int n = 1; n<=N; n++)
				{
					S.insert(n);
					if(S.size() == K)
						break;
				}
			}
			vector<int>v;
			for(auto it: S)
				v.push_back(it);
			cout<<10000<<endl;
			for(int i = 0; i<10000; i++)
				cout<<v[(i%K)]<<" ";
			cout<<endl;
		}

	}
	return 0;
}
