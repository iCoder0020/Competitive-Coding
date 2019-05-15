/*
ID: ishan_sang
PROG: STRCH
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int len;
		string S;
		char ch;
		cin>>len>>S>>ch;
		vector<int>ind;
		int ans = 0;
		ind.push_back(-1);
		for(int n = 0; n<len; n++)
			if(S[n] == ch)
				ind.push_back(n);

		for(int r = 1; r<ind.size(); r++)
		{
			int m = ind[r]-ind[r-1]-1;
			int n = len-ind[r]-1;
			ans += m + n + m*n + 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}