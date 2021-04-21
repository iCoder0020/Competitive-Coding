#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	string S;
	cin>>S;
	int cnt = 1, maxcnt = 1;
	for(int i = 1; i<S.length(); i++)
	{
		if(S[i] == S[i-1])
			cnt++;
		else
		{
			maxcnt = max(cnt, maxcnt);
			cnt = 1;
		}
	}
	cout<<max(cnt,maxcnt)<<endl;
	return 0;
}
