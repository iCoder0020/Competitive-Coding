#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		string S[N];
		map<char,int>MAP;
		for(int n = 0; n<N; n++)
		{
			cin>>S[n];
			for(auto it: S[n])
				MAP[it]++;
		}
		bool poss = true;
		for(auto it: MAP)
			if(it.second%N != 0)
				poss = false;
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
