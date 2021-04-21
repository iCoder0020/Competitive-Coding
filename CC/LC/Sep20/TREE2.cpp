#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		set<int>S;
		for(int n = 0; n<N; n++)
		{
			int x;
			cin>>x;
			if(x!=0)
				S.insert(x);
		}
		cout<<S.size()<<endl;
	}
	return 0;
}