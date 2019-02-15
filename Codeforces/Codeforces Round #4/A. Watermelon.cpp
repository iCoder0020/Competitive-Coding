/*
ID: iCoder0020
PROG: Watermelon
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int W;
	cin>>W;
	if(W<=3 || W&1)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	return 0;
}