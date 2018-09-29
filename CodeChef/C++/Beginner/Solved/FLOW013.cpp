/*
ID: ishan_sang
PROG: FLOW013
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		if(N<10)
		{
			cout<<"What an obedient servant you are!";
		}
		else
		{
			cout<<"-1";
		}
		cout<<"\n";
	}
	return 0;
}