#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	string S;
	cin>>S;
	unordered_map<string, int> MAP;
	int N = S.length();
	vector<vector<int>> freq_ahead(N, vector<int>(26, 0));
	for(int i = N-2; i>=0; i--)
	{
		for(int j = 0; j<26; j++)
		{
			if('a'+j == S[i+1])
				freq_ahead[i][j] = freq_ahead[i+1][j]+1;
			else
				freq_ahead[i][j] = freq_ahead[i+1][j];
		}
	}
	for(int i = 0; i<N; i++)
	{
		string T;
		T = "";
		T += S[i];
		MAP[T]++;
		for(int j = 0; j<26; j++)
		{
			string T_temp = T;
			T_temp += ('a'+j);
			MAP[T_temp] += freq_ahead[i][j];
		}
	}
	int ans = 0;
	for(auto it: MAP)
		ans = max(ans, it.second);
	cout<<ans<<endl;
	return 0;
}
