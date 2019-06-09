/*
ID: iCoder0020
PROG: Nauuo and Chess
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int n;
	cin>>n;
	int m = n/2 + 1;
	int i = 1, j = 1;
	cout<<m<<endl;
	while(n!=0 && j<=m)
	{
		cout<<i<<" "<<j<<endl;
		j++;
		n--;
	}
	j--;
	i++;
	while(n!=0 && i<=m)
	{
		cout<<i<<" "<<j<<endl;
		i++;
		n--;
	}
	return 0;
}