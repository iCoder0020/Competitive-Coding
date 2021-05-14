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
		int total = (1LL<<N)*2 - 2;
		int x = 1LL<<N;
		for(int i = 1; i<=N/2-1; i++)
			x += (1LL<<i);
		int y = total-x;
		cout<<abs(y-x)<<endl;
	}
	return 0;
}
