/*
ID: iCoder0020
PROG: Vus the Cossack and a Game
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int f(int a, int b)
{
	int c = ((a+1)/3)*((b+1)/2);
	if(a%3 == 1)
		c+= (b+1)/3;
	return c;
}

int32_t main()
{
	int n,m;
	cin>>n>>m;
	cout<<max(f(n,m), f(m,n))<<endl;
	return 0; 
}