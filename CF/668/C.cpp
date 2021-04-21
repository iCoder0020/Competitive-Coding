#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;
		cin>>N>>K;
		string S;
		cin>>S;
		bool poss = true;
		for(int n = N-1; n>=K; n--)
		{
			if(S[n-K] == '?' && S[n] != '?')
			{
				if(S[n-K] == '?' || S[n-K] == S[n])
					S[n-K] = S[n];
				else
					poss = false;
			}
		}
		for(int n = 0; n<N-K; n++)
		{
			if(S[n+K] == '?' && S[n] != '?')
			{
				if(S[n+K] == '?' || S[n+K] == S[n])
					S[n+K] = S[n];
				else
					poss = false;
			}
		}
		for(int n = K; n<N; n++)
		{
			if(S[n] != S[n-K])
				poss = false;
		}
		int cnt = 0;
		for(int n = 0; n<N; n++)
		{
			if(n>=K)
			{
				if(cnt < K/2)
					poss = false;
				if(S[n] == '?' && S[n-K] == '1')
					S[n] = '1';
				if(S[n-K] == '1')
					cnt--;
			}
			if(S[n] == '1')
				cnt++;
			if(cnt>K/2)
				poss = false;
			if(n+1 == K)
			{
				if(cnt<K/2)
				{
					for(int n = 0; n<K; n++)
					{
						if(S[n] == '?')
							S[n] = '1', cnt++;
						if(cnt == K/2)
							break;
						if(n == K-1)
							poss = false;
					}
				}
			}
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}