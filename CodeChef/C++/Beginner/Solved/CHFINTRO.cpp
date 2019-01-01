/*
ID: ishan_sang
PROG: CHFINTRO
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	cin>>T>>N;
	for(int t = 0; t<T; t++)
	{
		int r;
		cin>>r;
		if(r < N)
		{
			cout<<"Bad boi"<<endl;
		}
		else
		{
			cout<<"Good boi"<<endl;
		}
	}
	return 0;
}