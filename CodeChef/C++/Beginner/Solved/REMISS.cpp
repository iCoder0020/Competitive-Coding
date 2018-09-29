/*
ID: ishan_sang
PROG: REMISS
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
		if(A > B)
		{
			cout<<A<<" ";
		}
		else
		{
			cout<<B<<" ";
		}
		cout<<A+B<<"\n";
	}
	return 0;
}