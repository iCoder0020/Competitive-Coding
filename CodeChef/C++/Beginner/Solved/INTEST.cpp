/*
ID: ishan_sang
PROG: INTEST
LANG: C++                  
*/

#include <iostream>

using namespace std;

long int n,k,t[10000000];
int i,answer=0;

void run()
{
	cin>>n;
	cin>>k;
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		if(t[i]%k==0)
		{
			answer++;
		}
	}
	cout<<answer<<"\n";
}

int main()
{
	run();
	return 0;
}