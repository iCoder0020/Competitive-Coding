#include <bits/stdc++.h>

using namespace std;

#define int long long

#define t(n) inp[n].first
#define l(n) inp[n].second.first
#define h(n) inp[n].second.second
#define INF -1

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, T_initial;
		cin>>N>>T_initial;
		vector<pair<int,pair<int,int>>> inp(N);
		for(int n = 0; n<N; n++)
			cin>>t(n)>>l(n)>>h(n);
		sort(inp.begin(), inp.end());
		int lo = T_initial;
		int hi = T_initial;
		int time = 0;
		bool poss = true;
		for(int n = 0; n<N; n++)
		{	
			int t_hand = t(n)-time;
			lo = max({l(n), lo-t_hand});
			hi = min({h(n), hi+t_hand});
			// cout<<lo<<" "<<hi<<endl;
			if(hi<l(n) || lo>h(n))
			{
				poss = false;
				break;
			}
			time = t(n);
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
