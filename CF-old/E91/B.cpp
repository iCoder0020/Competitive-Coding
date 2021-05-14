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
		map<char,int>MAP;
		for(auto it: S)
			MAP[it]++;
		int r = MAP['R'], p = MAP['P'], s = MAP['S'];
		char o = 'R';
		if(r>=p && r>=s)
			o = 'P';
		if(p>=r && p>=s)
			o = 'S';
		string T="";
		for(int n = 0; n<S.length(); n++)
			T+=o;
		cout<<T<<endl;
	}
	return 0;
}
