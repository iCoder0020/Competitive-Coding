#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,L,R;
		cin>>N>>L>>R;
		int C[N];
		int ans = 0;
		map<int,int>mapL, mapR;
		for(int n = 0; n<N; n++)
		{
			cin>>C[n];
			if(n<L)
				mapL[C[n]]++;
			else
				mapR[C[n]]++;
		}
		for(pair<int,int> p: mapL)
		{
			int x = p.first;
			if(mapR.find(x) != mapR.end())
			{
				int l = p.second;
				int r = mapR[x];
				int paired = min(l,r);
				mapL[x] -= paired;
				mapR[x] -= paired;
			}
		}
		// cout<<"mapL: "<<endl;
		// for(pair<int,int>p: mapL)
		// 	cout<<p.first<<" "<<p.second<<endl;
		// cout<<"mapR: "<<endl;
		// for(pair<int, int>p: mapR)
		// 	cout<<p.first<<" "<<p.second<<endl;
		int diff = abs(L-R);
		if(R>L)
		{
			map<int,int> temp = mapL;
			mapL = mapR;
			mapR = temp;
		}
		for(pair<int,int>p: mapL)
		{
			if(diff == 0)
				break;
			int x = p.first;
			if(p.second >= 2)
			{
				int side_switch = min(diff/2, p.second/2);
				ans += side_switch;
				diff -= 2*side_switch;
				mapL[x] -= 2*side_switch;
			}
		}
		if(diff)
		{
			bool flag = false;
			for(pair<int,int>p: mapL)
			{
				int x = p.first;
				if(flag)
				{
					flag = false;
					mapL[x] -= 1;
					continue;
				}
				else
				{
					flag = true;
				}
				if(diff == 0)
					break;	
				ans += 2;
				diff -= 2;
				mapL[x] -= 1;
			}	
		}

		// cout<<"mapL: "<<endl;
		// for(pair<int,int>p: mapL)
		// 	cout<<p.first<<" "<<p.second<<endl;
		int cnt = 0;
		for(pair<int,int> p: mapL)
			cnt += p.second;
		cout<<ans+cnt<<endl;
	}
	return 0;
}