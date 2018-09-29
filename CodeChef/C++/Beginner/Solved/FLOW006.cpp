/*
ID: ishan_sang
PROG: FLOW006
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N,S;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		S=0;
		while(N)
		{
			S+=N%10;
			N/=10;
		}
		cout<<S<<"\n";
	}
	return 0;
}