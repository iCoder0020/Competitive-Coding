/*
ID: iCoder0020
PROG: Vus the Cossack and Strings
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	string a,b;
	cin>>a>>b;
	int m = 0;
	int d = 0;
	for(int i = 0; i<b.size(); i++)
	{
		if(a[i] != b[i])
			d++;
	}
	if(d%2 == 0)
		m++;
	for(int j = 0; j<a.size()-b.size(); j++)
	{
		
	}
	cout<<m<<endl;
	return 0; 
}