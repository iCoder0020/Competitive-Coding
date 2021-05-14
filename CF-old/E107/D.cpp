#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,K;
	cin>>N>>K;
	vector<vector<char>> possible(K, vector<char>(K));
	for(int i = 0; i<K; i++)
	{
		for(int j = 0; j<K; j++)
			possible[i][j] = 'a'+j;
	}
	vector<int> count(K, K);
	string S = "a";
	int sz = K*K;
	int n = 1;
	while(n<sz)
	{
		int last_letter = S[n-1]-'a';
		int max_val = 0, max_char = 0;
		for(int i = 0; i<K; i++)
		{
			if(possible[last_letter][i] != '!')
			{
				if(max_val < count[i])
				{
					max_val = count[i];
					max_char = i;
				}
			}
		}
		char c = max_char + 'a';
		possible[last_letter][max_char] = '!';
		count[last_letter]--;
		S += c;
		n++;
	}
	string ans;
	for(int i = 0; i<N/sz; i++)
		ans += S;
	ans += S.substr(0, N%sz);
	cout<<ans<<endl;
	return 0;
}
