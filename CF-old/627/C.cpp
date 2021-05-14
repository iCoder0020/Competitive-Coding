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
		S = "R"+S;
		S = S+"R";
		int N = S.length();
		int x = 1;
		int i = 0;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == 'R')
			{
				x = max(x, n-i);
				i = n;
			}
		}
		cout<<x<<endl;
	}
	return 0;
}
