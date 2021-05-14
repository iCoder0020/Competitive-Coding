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
		vector<int>raze, breach;
		for(int n = 0; n<N; n++)
		{
			if(n%2 == 0)
				raze.push_back(S[n]-'0');
			else
				breach.push_back(S[n]-'0');
		}
		int ans = 0;
		if(raze.size()>breach.size())
		{
			ans = 2;
			for(int x: raze)
				if(x&1)
					ans = 1;
		}
		else
		{
			ans = 1;
			for(int x: breach)
				if(x%2 == 0)
					ans = 2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
