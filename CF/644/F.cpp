#include <bits/stdc++.h>

using namespace std;

#define int long long

int diff(string A, string B, int M)
{
	int cnt = 0;
	for(int i = 0; i<M; i++)
		if(A[i]!=B[i])
			cnt++;
	return cnt;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		string S[N];
		for(int n = 0; n<N; n++)
			cin>>S[n];
		string ans = (N==1)?S[0]:"-1";
		for(int i = 0; i<M; i++)
		{
			string T = S[0];
			for(char c = 'a'; c<='z'; c++)
			{
				T[i] = c;
				for(int j = 1; j<N; j++)
				{
					if(diff(S[j], T, M)>1)
						break;
					if(j == N-1)
						ans = T;
				}
			}
			if(ans != "-1")
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
