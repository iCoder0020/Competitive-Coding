/*
ID: iCoder0020
PROG: Restoring Three Numbers
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int a[4];
	for(int n = 0; n<4; n++)
		cin>>a[n];
	sort(a, a+4);
	for(int n = 0; n<3; n++)
		cout<<a[3]-a[n]<<" ";
	cout<<endl;
	return 0;
}