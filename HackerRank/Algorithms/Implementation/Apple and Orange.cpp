/*
ID: iCoder0020
PROG: Apple and Orange
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int s,t,a,b,m,n,d;
	int apple=0,orange=0;
	cin>>s>>t;
	cin>>a>>b;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>d;
		if(a+d>=s && a+d<=t)
			apple++;
	}
	cout<<apple<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>d;
		if(b+d>=s && b+d<=t)
			orange++;
	}
	cout<<orange<<"\n";
	return 0;
}