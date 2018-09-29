/*
ID: ishan_sang
PROG: RECTANGL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, RECT[4];
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		for(int i = 0; i<4; i++)
		{
			cin>>RECT[i];
		}
		sort(RECT, RECT+4);
		if(RECT[0] == RECT[1] && RECT[2] == RECT[3])
		{
			cout<<"YES\n";
			continue;
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}