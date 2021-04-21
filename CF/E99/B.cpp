#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX 2000005
#define LIM 1000005

int32_t main()
{
	int TC;
	cin>>TC;
	int N = 1500;
	vector<int>ans(N);
	for(int n = 0; n<N; n++)
		ans[n] = (n*(n+1))/2;
	while(TC--)
	{
		int X;
		cin>>X;
		for(int i = 0; i<N; i++)
		{
			if(ans[i]>=X)
			{
				int sol = i+ans[i]-X;
				if(ans[i]-X-1 >= 1 && ans[i]-X-1 <= i)
					sol = min(sol, i);
				cout<<sol<<endl;
				break;
			}
		}
	}
	return 0;
}
