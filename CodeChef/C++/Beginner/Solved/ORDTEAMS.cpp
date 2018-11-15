/*
ID: ishan_sang
PROG: ORDTEAMS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int a[], int b[], int c[])
{
	if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2] && !((a[0]==b[0])&&(a[1]==b[1])&&(a[2]==b[2])))
	{
		if(b[0]<=c[0] && b[1]<=c[1] && b[2]<=c[2] && !((b[0]==c[0])&&(b[1]==c[1])&&(b[2]==c[2])))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	int S[3][3];
	for(int t = 0; t<T; t++)
	{
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				cin>>S[i][j];
			}
		}
		if(check(S[0], S[1], S[2]) || check(S[0], S[2], S[1]) || check(S[1], S[0], S[2]) || check(S[1], S[2], S[0]) || check(S[2], S[0], S[1]) || check(S[2], S[1], S[0]))
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}