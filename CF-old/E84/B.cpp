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
		vector<vector<int>> list(N);
		vector<set<int>> d(N);
		vector<bool> got(N, false);
		for(int n = 0; n<N; n++)
		{
			int K;
			cin>>K;
			for(int k = 0; k<K; k++)
			{
				int x;
				cin>>x;
				list[n].push_back(x);
				d[n].insert(x);
			}
		}
		set<int> S;
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<list[n].size(); m++)
			{
				if(S.find(list[n][m]) == S.end())
				{
					S.insert(list[n][m]);
					got[n] = true;
					break;
				}
			}
		}
		int prince = 0;
		for(int n = 1; n<=N; n++)
		{
			if(S.find(n) == S.end())
			{
				prince = n;
				break;
			}
		}

		int idx = 0;

		if(prince != 0)
		{
			for(int n = N-1; n>=0; n--)
			{
				if(got[n])
					continue;
				if(d[n].find(prince) == d[n].end())
				{
					idx = n+1;
					break;
				}
			}
		}

		if(idx == 0)
			cout<<"OPTIMAL";
		else
		{
			cout<<"IMPROVE"<<endl;
			cout<<idx<<" "<<prince;
		}
		cout<<endl;
	}
	return 0;
}
