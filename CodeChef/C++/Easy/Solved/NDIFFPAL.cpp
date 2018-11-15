/*
ID: ishan_sang
PROG: NDIFFPAL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int ax=0;ax<T;ax++)
	{
		int n;
		cin>>n;
	    char a='a';
		for(int i=1;i<=n;i++)
		{
			cout<<a;
			a++;
			if(i%26==0)
				a='a';
		}
		cout<<"\n";
	}
	return 0;
}