/*
ID: ishan_sang
PROG: EXAM1
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		string s,t;
		cin>>s>>t;
		int cnt = 0;
		for(int i = 0; i<N; i++)
		{
			if(s[i] == t[i])
				cnt++;
			else if(t[i] != 'N')
				i++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
