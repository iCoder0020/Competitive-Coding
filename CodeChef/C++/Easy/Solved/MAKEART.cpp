/*
ID: ishan_sang
PROG: MAKEART
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
		int ar[n];
		for(int i=0;i<n;i++)
			cin>>ar[i];
		if(n<3)
		{
			cout<<"No\n";
			continue;
		}
		int is=0;
		for(int i=0;i<n-2;i++)
		{
			if(ar[i]==ar[i+1]&&ar[i]==ar[i+2])
			{
				is=1;
				break;
			}
		}
		if(is==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}