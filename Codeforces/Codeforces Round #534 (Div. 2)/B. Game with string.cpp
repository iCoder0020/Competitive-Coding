/*
ID: iCoder0020
PROG: Game with string
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	int count = 0;
	for(int n = 0; n<S.length(); n++)
	{
		if(S[n] == S[n+1])
		{
			S.erase(S.begin()+n);
			S.erase(S.begin()+n);
			count++;
			n=max(-1,n-2);
		}
	}
	if(count%2 == 0)
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
	cout<<endl;
	return 0;
}