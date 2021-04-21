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
		vector<int>lcount(26,0);
		for(auto it: S)
			lcount[it-'a']++;
		for(int n = 0; n<26; n++)
		{
			if(lcount[n]!=0)
			{
				cout<<(char)('a'+n)<<" "<<lcount[n]<<", ";
			}
		}
		cout<<endl;
	}
	return 0;
}
