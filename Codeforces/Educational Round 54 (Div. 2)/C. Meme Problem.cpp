/*
ID: iCoder0020
PROG: Meme Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int d;
		cin>>d;
		long double a,b;

		if(d == 0)
		{
			a = 0;
			b = 0;
			cout<<setprecision(10)<<fixed<<"Y "<<a<<" "<<b<<endl;
		}
		else
		{
			if((d*d-4*d) < 0)
			{
				cout<<"N"<<endl;
			}
			else
			{
				a = ((long double)(d) + sqrt((long double)(d*d-4*d)))/2.0;
				if(a == 0)
				{
					cout<<"N"<<endl;
				}
				else
				{
					b = ((long double)(d))/a;
					cout<<setprecision(10)<<fixed<<"Y "<<a<<" "<<b<<endl;
				}
			}
		}
	}
	return 0;
}