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
		sort(S.begin(), S.end());
		unordered_map<char,int>MAP;
		for(auto it: S)
			MAP[it]++;
		if(S[0] != S[K-1])
		{
			cout<<S[K-1]<<endl;
			continue;
		}
		vector<string>answers(K);
		for(int j = 0; j<K; j++)
		{
			for(char x = 'a'; x<='z'; x++)
			{
				if(MAP[x] == 0)
					continue;
				answers[j] += x;
				MAP[x]--;
				break;
			}
		}
		int cnt = 0;
		for(auto it: MAP)
			if(it.second != 0)
				cnt++;
		if(cnt == 1)
		{
			for(int i = 1; i<=N/K; i++)
			{
				for(char x = 'a'; x<='z'; x++)
				{
					for(int j = 0; j<K; j++)
					{
						if(MAP[x] == 0)
							continue;
						answers[j] += x;
						MAP[x]--;
					}
				}
			}
		}
		else
		{
			for(char x = 'a'; x<='z'; x++)
			{
				for(int y = 0; y<MAP[x]; y++)
					answers[0] += x;
			}
		}
		string maxm = "";
		for(auto it: answers)
			maxm = max(maxm, it);
		cout<<maxm<<endl;
	}
	return 0;
}
