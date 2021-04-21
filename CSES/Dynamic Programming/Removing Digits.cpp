#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9

int32_t main()
{
	int X;
	cin>>X;
	int DP[X+1];
	DP[0] = 0;
	for(int n = 1; n<=X; n++)
	{
		DP[n] = INF;
		if(n<10)
			DP[n] = 1;
		else
		{
			int m = n;
			while(m)
			{
				int x = m%10;
				DP[n] = min(DP[n], DP[n-x]+1);
				m/=10;
			}
		}
	}
	cout<<DP[X]<<endl;
	return 0;
}
