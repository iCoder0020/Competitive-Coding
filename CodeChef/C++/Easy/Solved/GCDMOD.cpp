/*
ID: ishan_sang
PROG: GCDMOD
LANG: C++                  
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MOD 1000000007

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
	int T;
	li A,B,N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>A>>B>>N;
		if(A == B)
		{
			cout<<(modular_exponentiation(A,N,MOD)+modular_exponentiation(B,N,MOD))%MOD<<"\n";
		}
		else
		{
			li size = 2*sqrt(abs(A-B));
			li factors[size] = {0};
			int head = 0;
			int rear = size-1;
			for(li i = 1; i<=sqrt(A-B); i++)
			{
				if((A-B)%i == 0)
				{
					factors[head] = i;
					head++;
					factors[rear] = (A-B)/i;
					rear--;
				}
			}
			for(int i = size - 1; i>=0; i--)
			{
				if(factors[i] == 0)
				{
					i = head;
				}
				else
				{
					if((modular_exponentiation(A,N,factors[i])+modular_exponentiation(B,N,factors[i]))%factors[i] == 0)
					{
						cout<<factors[i]<<"\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}