#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S;
		cin>>S;
		set<char> alpha;
		vector<char> arr(64, '$');
		int i = 32;
		bool poss = true;
		for(auto it : S)
		{
			if(alpha.find(it) == alpha.end())
			{
				alpha.insert(it);
				if(arr[i] == '$')
					arr[i] = it;
				else
				{
					if(arr[i+1] == '$')
					{
						arr[i+1] = it;
						i++;
					}
					else if(arr[i-1] == '$')
					{
						arr[i-1] = it;
						i--;
					}
					else
						poss = false;
				}
			}
			else
			{
				int j = i;
				for(int n = 0; n<64; n++)
					if(arr[n] == it)
						i = n;
				if(abs(j-i)>1)
					poss = false;
			}
		}
		if(!poss)
			cout<<"NO"<<endl;
		else
		{
			int start = -1;
			for(int n = 0; n<64; n++)
				if(arr[n] != '$')
				{
					start = n;
					break;
				}

			vector<char> ans;
			for(int n = start; arr[n]!='$'; n++)
				ans.push_back(arr[n]);
			for(char ch = 'a'; ch<='z'; ch++)
				if(alpha.find(ch) == alpha.end())
					ans.push_back(ch);
			cout<<"YES"<<endl;
			for(auto it: ans)
				cout<<it;
			cout<<endl;
		}	
	}
	return 0;
}

