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
		vector<int>arr(N);
		int cnt[101] = {0};
		for(int n = 0; n<N; n++)
		{
			cin>>arr[n];
			cnt[arr[n]]++;
		}
		int ans = 0;
		bool A = false, B = false;
		for(int n = 0; n<=100; n++)
		{
			if(A && B)
				break;
			for(int i = 1; i<=2; i++)
			{
				if(cnt[n] >= 2)
					continue;
				if(cnt[n] == 1)
				{
					if(!B)
					{
						B = true;
						ans += n;
					}
				}
				else
				{
					if(!A)
					{
						A = true;
						ans += n;
					}
					if(!B)
					{
						B = true;
						ans += n;
					}
				}
			}
		}
		if(!A)
			ans += 101;
		if(!B)
			ans += 101;
		cout<<ans<<endl;
	}
	return 0;
}
