/*
ID: ishan_sang
PROG: EATTWICE
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		pair<int,int> V[N];
		int val = 0, day;
		for(int n = 0; n<N; n++)
		{
			cin>>V[n].first>>V[n].second;
			if(V[n].second > val)
			{
				val = V[n].second;
				day = V[n].first;
			}
		}
		int ans = val;
		for(int n = 0; n<N; n++)
		{
			if(V[n].first != day)
			{
				ans = max(ans, val + V[n].second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
