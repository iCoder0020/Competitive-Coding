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
		int A[N];
		map<int, int> m;
		int ans = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			m[A[n]-n]++;
		}
		for(pair<int,int> p: m)
		{
			int x = p.second;
			ans += (x)*(x-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
