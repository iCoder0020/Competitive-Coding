/*
ID: ishan_sang
PROG: PINS
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N;
	int m;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>N;
		cout<<"1 1";
		m = (N%2 == 0)?N/2:(N-1)/2;
		for(int n = 0; n<m; n++)
		{
			cout<<"0";
		}
		cout<<"\n";
	}
	return 0;
}