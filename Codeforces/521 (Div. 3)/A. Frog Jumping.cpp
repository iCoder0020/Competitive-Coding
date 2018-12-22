/*
ID: iCoder0020
PROG: Frog Jumping
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
		long long int A,B,K;
		cin>>A>>B>>K;
		cout<<A*(K/2+K%2) - B*(K/2)<<endl;
	}
	return 0;
}