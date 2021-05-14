#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int H,M;
		cin>>H>>M;
		int x = (23-H)*60 + (60-M);
		cout<<x<<endl;
	}
	return 0;
}
