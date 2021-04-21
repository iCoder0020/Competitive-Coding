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
		int x = N/2;
		int y = 2*x;
		cout<<__gcd(x,y)<<endl;
	}
	return 0;
}
