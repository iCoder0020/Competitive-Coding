/*
ID: iCoder0020
PROG: Sasha and Sticks
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned long long int n,k;
	cin>>n>>k;
	if((n/k)%2 == 0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	return 0;
}