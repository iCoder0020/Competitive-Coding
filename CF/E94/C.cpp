#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S;
		cin>>S;
		int X;
		cin>>X;
		int N = S.length();
		string W(N,'?');
		bool poss = true;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '0')
			{
				if(n-X>=0)
					W[n-X]='0';
				if(n+X<N)
					W[n+X]='0';
			}
		}
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '1')
			{
				int cnt = 0;
				if(n-X>=0 && W[n-X]!='0')
					W[n-X]='1', cnt++;
				if(n+X<N && W[n+X]!='0')
					W[n+X]='1', cnt++;
				if(cnt == 0)
					poss = false;

			}
		}
		for(int n = 0; n<N; n++)
			if(W[n] == '?')
				W[n] = '1';
		if(poss)
			cout<<W<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
