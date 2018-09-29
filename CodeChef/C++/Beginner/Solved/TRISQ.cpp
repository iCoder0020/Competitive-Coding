/*
ID: ishan_sang
PROG: TRISQ
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
	int T,B;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>B;
		cout<<(((int)(B)/2)*(int)((int)(B-2)/2))/2<<"\n";
	}
	return 0;
}
