#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	string S;
	cin>>S;
	int ans = 0;
	int N = S.length();
	for(int n = 0; n<N; n++)
	{
		int cnt = 0, q = 0;
		for(int m = n; m<N; m++)
		{
			if(S[m] == '(')
				cnt++;
			else if(S[m] == ')')
			{
				cnt--;
				if(cnt<0)
				{
					if(q == 0)
						break;
					else
						cnt+=2, q--;
				}
			}
			else
			{
				q++;
				cnt--;
				if(cnt<0)
					cnt+=2, q--;
			}
			if(cnt == 0)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
