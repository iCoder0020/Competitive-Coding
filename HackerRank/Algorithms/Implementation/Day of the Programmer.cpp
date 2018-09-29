/*
ID: iCoder0020
PROG: Day of the Programmer
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int YEAR;
	cin>>YEAR;
	if(YEAR == 1918)
	{
		cout<<"26.09.1918\n";
	}
	else if(YEAR < 1918)
	{
		if(YEAR%4 == 0)
		{
			cout<<"12.09."<<YEAR<<"\n";
		}
		else
		{
			cout<<"13.09."<<YEAR<<"\n";
		}
	}
	else
	{
		if(YEAR%400 == 0 || (YEAR%4 == 0 && YEAR%100!=0))
		{
			cout<<"12.09."<<YEAR<<"\n";
		}
		else
		{
			cout<<"13.09."<<YEAR<<"\n";
		}
	}
	return 0;
}