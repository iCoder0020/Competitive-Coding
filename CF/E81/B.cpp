#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,X;
		cin>>N>>X;
		string S;
		cin>>S;

		int cnt[N];
		cnt[0] = (S[0] == '0')?1:-1;
		for(int n = 1; n<N; n++)
		{
			if(S[n] == '0')
				cnt[n] = cnt[n-1]+1;
			else
				cnt[n] = cnt[n-1]-1;
		}

		int sum = cnt[N-1];
		int ans = 0;

		if(sum == 0)
		{
			for(int n = 0; n<N; n++)
			{
				if(cnt[n] == X)
				{
					ans = -1;
					break;
				}
				if(n == N-1)
					ans = 0;
			}
		}

		else
		{
			if(X == 0)
				ans++;	
			for(int n = 0; n<N; n++)
				if((abs(X-cnt[n]))%abs(sum) == 0 && ((X-cnt[n])/(sum))>=0)
					ans++;
		}

		cout<<ans<<endl;
	}
	return 0;
}

