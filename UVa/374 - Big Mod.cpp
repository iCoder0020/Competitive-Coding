/*
ID: iCoder0020
PROG: 374 - Big Mod
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li modular_exponentiation(li a, li b, li c)
{
	li result = 1;
	a = a%c;
	while(b>0)
	{
		if(b&1)
		{
			result = (result * a)%c;
		}
		b = b>>1;
		a = (a*a)%c;
	}
	return result;
}

int main()
{
	li a,b,c;
	char ch;
	while(cin>>a)
	{
		cin>>b>>c;
		cout<<modular_exponentiation(a,b,c)<<"\n";
	}
	return 0;
}