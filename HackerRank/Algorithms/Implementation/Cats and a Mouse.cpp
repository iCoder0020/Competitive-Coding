/*
ID: iCoder0020
PROG: Cats and a Mouse
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int Q;
	cin>>Q;
	int X,Y,Z;
	for(int q = 0; q<Q; q++)
	{
		cin>>X>>Y>>Z;
		int distA = abs(X-Z);
		int distB = abs(Y-Z);
		if(distA<distB)
		{
			cout<<"Cat A\n";
		}
		else if(distB<distA)
		{
			cout<<"Cat B\n";
		}
		else
		{
			cout<<"Mouse C\n";
		}
	}
	return 0;
}