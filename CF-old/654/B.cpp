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
		int N,R;
		cin>>N>>R;
		int y = min(N,R+1);
		int x = ((y)*(y-1))/2;
		if(R>=N)
			x++;
		cout<<x<<endl;
	}
	return 0;
}
