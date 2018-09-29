/*
ID: ishan_sang
PROG: TRICOIN
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	long T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		cout<<(int)(((-1+(sqrt(1+8*N)))/2))<<"\n";
	}
	return 0;
}