/*
ID: ishan_sang
PROG: GIVCANDY
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li GCD(li a, li b)
{
	if(b>a)
	{
		return GCD(b, a);
	}
	if(b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a%b);
	}
}

int main()
{
	int T;
	cin>>T;
	for(int ax=0;ax<T;ax++)
	{
		li a,b,c,d;
		cin>>a>>b>>c>>d;
	    li diff=abs(a-b);
	    li gcd=GCD(c,d);
		cout<<min(diff%gcd,gcd-diff%gcd)<<"\n";
	}
	return 0;
}