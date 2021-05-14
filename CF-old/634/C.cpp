#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX 200005

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		map<int,int>cnt;
		int mc = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			cnt[A[n]]++;
			if(cnt[A[n]]>mc)
				mc = cnt[A[n]];
		}
		set<int>S;
		for(auto it: A)
			S.insert(it);
		int x = min((int)(S.size()-1), mc);
		if(mc-1>=x+1)
			x++;
		cout<<x<<endl;
	}
	return 0;
}
