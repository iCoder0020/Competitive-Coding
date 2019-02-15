/*
ID: ishan_sang
PROG: CHEFING
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int count = 0;
		int char_count[N][26];
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<26; j++)
			{
				char_count[i][j] = 0;
			}
		}
		for(int n = 0; n<N; n++)
		{
			string S;
			cin>>S;
			for(int m = 0; m<S.length(); m++)
			{
				char_count[n][S[m]-'a']++;
			}
		}
		for(int m = 0; m<26; m++)
		{
			for(int n = 0; n<N; n++)
			{
				if(char_count[n][m] == 0)
				{
					break;
				}
				if(n == N-1)
				{
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}