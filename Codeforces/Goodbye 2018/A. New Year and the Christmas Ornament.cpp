/*
ID: iCoder0020
PROG: New Year and the Christmas Ornament
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int y,b,r;
	cin>>y>>b>>r;
	while(y+1>b || y+2>r)
	{
		y--;
	}
	cout<<3*y+3<<endl;
	return 0;
}