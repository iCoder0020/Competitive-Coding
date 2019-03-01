/*
ID: icoder_0020
PROG: Counting Frog Paths
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int X,Y,s,T;
	cin>>X>>Y>>s>>T;
	int temp = T-X-Y;
	if(temp >=0)
	{
		if(temp >= 2*s)
		{
			cout<<(s+1)*(s+1)<<endl;
		}
		else if(temp <= s)
		{
			cout<<((temp+1)*(temp+2))/2<<endl;
		}
		else
		{
			temp=2*s-temp;
			cout<<(s+1)*(s+1) - ((temp+1)*(temp+2))/2<<endl;
		}
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
