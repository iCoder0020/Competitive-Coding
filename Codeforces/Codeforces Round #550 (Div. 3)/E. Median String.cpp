/*
ID: iCoder0020
PROG: Median String
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long 

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	string S,T;
	int ans[N];
	cin>>S>>T;
	int carry = 0;
	for(int n = N-1; n>=0; n--)
	{
		ans[n] = (carry + S[n]-'a' + T[n]-'a');
		carry = ans[n]/26;
		ans[n]%=26;
	}
	for(int n = 0; n<N; n++)
	{
		int s = (carry*26+ ans[n]);
		carry = s%2;
		ans[n] = s/2;
		cout<<(char)(ans[n]+'a');
	}
	cout<<endl;
	return 0;
}