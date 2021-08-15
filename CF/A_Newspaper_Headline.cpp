#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main()
{
	string S,T;
	cin>>S>>T;
	int N = S.length();
	vector<bool>got(26,false);
	for(auto it: S)
		got[it-'a'] = true;
	for(auto it: T)
	{
		if(!got[it-'a'])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	vector<vector<int>>nextfrom(N,vector<int>(26, -1));
	nextfrom[N-1][S[N-1]-'a'] = N-1;
	for(int n = N-2; n>=0; n--)
	{
		for(int m = 0; m<26; m++)
			nextfrom[n][m] = nextfrom[n+1][m];
		nextfrom[n][S[n+1]-'a'] = n+1;
		nextfrom[n][S[n]-'a'] = n;
	}
	int cnt = 1;
	int i = 0;
	for(auto it: T)
	{
		while(1)
		{
			if(i == N || nextfrom[i][it-'a'] == -1)
			{
				cnt++;
				i = 0;
				continue;
			}
			i = nextfrom[i][it-'a']; 
			if(S[i] == it)
			{
				i++;
				break;			
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}