#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N, K;
		cin>>N>>K;
		string S;
		cin>>S;
		vector<int>next1(N, -1);
		int prev = INF;
		for(int n = N-2; n>=0; n--)
		{
			if(S[n+1] == '1')
				next1[n] = n+1;
			else
				next1[n] = next1[n+1];
		}
		int cnt = 0;
		for(int n = 0; n<N; n++)
		{
			if(S[n]=='1')
			{
				prev = n;
				continue;
			}
			if(next1[n]==-1 || next1[n]>n+K)
			{
				if(prev == INF || prev<n-K)
				{
					prev = n;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
