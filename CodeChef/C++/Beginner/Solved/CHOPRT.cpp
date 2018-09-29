/*
ID: ishan_sang
PROG: CHOPRT
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int A, B;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>A>>B;
		if(A < B)
		{
			cout<<"<\n";
		}
		else if(A > B)
		{
			cout<<">\n";
		}
		else
		{
			cout<<"=\n";
		}
	}
	return 0;
}