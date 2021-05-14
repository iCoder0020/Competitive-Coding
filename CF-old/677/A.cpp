#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	map<int,int>MAP;
	int cnt = 0;
	for(int n = 1; n<=9; n++)
	{
		int num = 0;
		for(int i = 0; i<4; i++)
		{
			num = 10*num + n;
			MAP[num] = cnt;
			cnt++;
		}
	}
	while(TC--)
	{
		int X;
		cin>>X;	
		int turn = MAP[X];
		int arr[4] = {1,2,3,4};
		int ans = 0;
		for(int n = 0; n<=turn; n++)
			ans += arr[n%4];
		cout<<ans<<endl;
	}
	return 0;
}
