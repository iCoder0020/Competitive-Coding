/*
ID: ishan_sang
PROG: FLOW016
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li gcd(li a, li b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}

int main()
{
	li T,A,B;
	cin>>T;
	for(li t = 0; t<T; t++)
	{
		cin>>A>>B;
		li GCD = gcd(A,B);
		cout<<GCD<<" "<<(A*B)/GCD<<endl;
	}
	return 0;
}