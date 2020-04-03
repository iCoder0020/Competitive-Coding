#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 10000000

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S,T;
		cin>>S>>T;
		int N = S.length();
		int M = T.length();
		int char_there[26] = {0};
		for(auto it: S)
			char_there[it-'a'] = 1;
		bool poss = 1;
		for(auto it: T)
			if(char_there[it-'a'] == 0)
				poss = 0;
		if(poss == 0)
			cout<<-1<<endl;
		else
		{
			int next_char[N][26];
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<26; j++)
					next_char[i][j] = INF;
			}

			for(int n = N-1; n>=1; n--)
			{
				char ch = S[n];
				for(int i = 0; i<26; i++)
				{
					if(ch == 'a'+i)
						next_char[n-1][i] = n;
					else
						next_char[n-1][i] = next_char[n][i];
				}
			}

			// for(int n = 0; n<N; n++)
			// {
			// 	for(int m = 0; m<26; m++)
			// 		cout<<next_char[n][m]<<" ";
			// 	cout<<endl;
			// }

			int cnt = 1;
			char ch;
			int n = 0, m = 0;
			while(1)
			{
				ch = T[m];
				if(S[n] == ch)
				{
					n++;
					m++;
				}
				else
					n = next_char[n][ch-'a'];
				if(m == M)
					break;
				if(n>=N)
				{
					n = 0;
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

