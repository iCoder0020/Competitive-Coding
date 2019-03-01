/*
ID: iCoder0020
PROG: Hit the Lottery
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int bills[5] = {100,20,10,5,1};
	int N;
	cin>>N;
	int amount = N;
	int coins = 0;
	for(int n = 0; n<5; n++)
	{
		coins += amount/bills[n];
		amount -= (amount/bills[n])*bills[n];
	}
	cout<<coins<<endl;
	return 0;
}