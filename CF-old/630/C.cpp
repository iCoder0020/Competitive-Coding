#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		string S;
		cin>>S;
		vector<string>x;
		vector<pair<int,string>>y;
		for(int i = 0; i<N; i+=K)
			x.push_back(S.substr(i,K));
		vector<vector<int>> char_freq(K, vector<int>(26,0));
		for(auto it: x)
			for(int n = 0; n<K; n++)
				char_freq[n][it[n]-'a']++;
		int min_change = N-1;
		string res;
		for(int i = 0; i<K/2; i++)
		{
			int max_occ = 0;
			char ch;
			for(char c = 'a'; c<='z'; c++)
			{
				if(char_freq[i][c-'a'] + char_freq[K-1-i][c-'a'] >= max_occ)
				{
					max_occ = char_freq[i][c-'a'] + char_freq[K-1-i][c-'a'];
					ch = c;
				}
			}
			res += ch;
		}
		string temp = res;
		reverse(temp.begin(), temp.end());
		if(K&1)
		{
			int i = K/2;
			int max_occ = 0;
			char ch;
			for(char c = 'a'; c<='z'; c++)
			{
				if(char_freq[i][c-'a'] + char_freq[K-1-i][c-'a'] >= max_occ)
				{
					max_occ = char_freq[i][c-'a'] + char_freq[K-1-i][c-'a'];
					ch = c;
				}
			}
			res += ch;
			res += temp;
		}
		else
		{
			res += temp;
		}
		// cout<<res<<endl;
		int ans = 0;
		for(int n = 0; n<N; n++)
			if(S[n] != res[n%K])
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
