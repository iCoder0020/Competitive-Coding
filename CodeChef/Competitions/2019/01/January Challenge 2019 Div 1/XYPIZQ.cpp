/*
ID: ishan_sang
PROG: XYPIZQ
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li GCD(li a, li b)
{
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
	for(int t = 0; t<T; t++)
	{
		li N;
		int choice;
		li x,y,z;
		cin>>N>>choice;
		cin>>x>>y>>z;
		li num, den, gcd;
		den = 2*N+1;	
		if(x == z)
		{
			num = x;
		}
		else
		{
			if(choice == 1)
			{
				num = den - z;
			}
			else if(choice == 3)
			{
				num = den - x;
			}
			else
			{
				num = den - 2*y;
			}
		}
		gcd = GCD(num, den);
		num /= gcd;
		den /= gcd;
		cout<<num<<" "<<den<<endl;
	}
	return 0;
}
