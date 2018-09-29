/*
ID: iCoder0020
PROG: Largest prime factor
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

typedef long long int ll;

int main()
{
	int T;
	ll N;
	bool flag;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		flag = false;
		cin>>N;
		while(N%2 == 0)
		{
			N /= 2;
		}
		if(N == 1)
		{
			cout<<"2\n";
			flag = true;
		}
		else
		{
			for(int p = 3; p<=sqrt(N); p += 2)
			{
				while(N%p == 0)
				{
					N /= p;
				}
				if(N == 1)
				{
					cout<<p<<"\n";
					flag = true;
					break;
				}
			}
		}
		if(!flag)
		{
			cout<<N<<"\n";
		}
	}
	return 0;
}