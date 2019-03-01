/*
ID: ishan_sang
PROG: THREEFR
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int X,Y,Z;
		cin>>X>>Y>>Z;
		if(X == Y+Z || Y == X+Z || Z == X+Y)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}