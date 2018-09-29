/*
ID: ishan_sang
PROG: FSQRT
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		cout<<(int)(sqrt(N))<<"\n";
	}
	return 0;
}