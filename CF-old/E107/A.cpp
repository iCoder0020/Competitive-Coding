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
		int ans = 0;
		for(int n = 0; n<N; n++)
		{
			int x;
			cin>>x;
			if(x == 1 || x == 3)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
