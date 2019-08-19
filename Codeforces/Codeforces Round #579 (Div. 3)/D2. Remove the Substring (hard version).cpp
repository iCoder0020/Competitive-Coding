/*
ID: iCoder0020
PROG: Remove the Substring (hard version)
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	string S,T;
	cin>>S>>T;
	int s = S.size();
	int t = T.size();
	int pre[t];
	int suf[t];
	int i,j;
	i = 0, j = 0;
	while(i<t && j<s)
	{
		if(T[i] == S[j])
		{
			pre[i] = j;
			i++;
		}
		j++;
	}
	i = t-1, j = s-1;
	while(i>=0 && j>=0)
	{
		if(T[i] == S[j])
		{
			suf[i] = j;
			i--;
		}
		j--;
	}
	// for(i = 0; i<t; i++)
	// 	cout<<pre[i]<<" ";
	// cout<<endl;
	// for(i = 0; i<t; i++)
	// 	cout<<suf[i]<<" ";
	// cout<<endl;
	int ans = max(s-pre[t-1]-1, suf[0]);
	for(int n = 0; n<t-1; n++)
		ans = max(ans, suf[n+1]-pre[n]-1);
	cout<<ans<<endl;
	return 0; 
}