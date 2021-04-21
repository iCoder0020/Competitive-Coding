#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e6

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		set<int>S;
		vector<int>v;
		for(int n = 0; n<2*N; n++)
		{
			int x;
			cin>>x;
			if(S.find(x) ==  S.end())
			{
				v.push_back(x);
				S.insert(x);
			}
		}
		for(auto it: v)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
