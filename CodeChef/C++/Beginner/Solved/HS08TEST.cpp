/*
ID: ishan_sang
PROG: HS08TEST
LANG: C++                  
*/

#include <iostream>
#include <iomanip>

using namespace std;

float to_withdraw,balance;

void input()
{
	cin>>to_withdraw;
	cin>>balance;
}

void withdraw()
{
	if(((int)to_withdraw%5==0) && (to_withdraw+0.50<=balance))
	{
		balance-=(to_withdraw+0.50);
	}
	cout<<fixed<<setprecision(2)<<balance<<"\n";
}

int main()
{
	input();
	withdraw();
	return 0;
}