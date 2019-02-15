/*
ID: iCoder0020
PROG: Gennady and a Card Game
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	char ch[2];
	cin>>ch[0]>>ch[1];
	char table[5][2];
	bool possible = false;
	for(int n = 0; n<5 ; n++)
	{
		cin>>table[n][0]>>table[n][1];
		if(ch[0] == table[n][0] || ch[1] == table[n][1])
		{
			possible = true;
		}
	}
	if(possible)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	cout<<endl;
	return 0;
}