#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		int first = -1, last = -1;
		for(int n = 0; n<S.length(); n++)
		{
			if(S[n] == '1')
			{
				if(first == -1)
					first = n;
				last = n;
			}
		}
		if(first == -1)
			cout<<"0"<<endl;
		else
		{
			int ans = 0;
			for(int n = first; n<=last; n++)
				if(S[n] == '0')
					ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}

