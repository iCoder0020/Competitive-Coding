#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A,B;
		cin>>A>>B;
		int X = (A&B);
		int ans = (A^X)+(B^X);
		cout<<ans<<endl;
	}
	return 0;
}
