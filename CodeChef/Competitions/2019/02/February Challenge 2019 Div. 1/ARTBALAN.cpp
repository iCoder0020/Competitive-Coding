/*
ID: ishan_sang
PROG: ARTBALAN
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int char_count[26] = {0};
		string S;
		cin>>S;
		int len = S.length();
		int ans;
		int min_ans = INT_MAX;
		for(int n = 0; n<len; n++)
		{
			char_count[S[n] - 'A']++;
		}
		sort(char_count, char_count+26, greater<int>());
		for(int distinct = 1; distinct<=min(len,26); distinct++)
		{
			if(len % distinct == 0)
			{
				ans = 0;
				int freq = len/distinct;
				int extra = 0;
				for(int n = 0; n<distinct; n++)
				{
					if(char_count[n] + extra < freq)
					{
						extra = 0;
						ans += freq - char_count[n] - extra;
					}
					else
					{
						extra -= freq - char_count[n];
						if(extra < 0)
						{
							ans -= extra;
						}
						extra = 0;
					}
				}
				//cout<<distinct<<" "<<ans<<endl;
				min_ans = min(min_ans, ans);
			}
		}
		cout<</*S<<" "<<*/min_ans<<endl;
	}
	return 0;
}