/*
ID: ishan_sang
PROG: FLOW004
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	int first_digit,last_digit;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		first_digit=0;
		last_digit=N%10;
		while(N/10)
		{
			N/=10;
			first_digit=N%10;
		}
		cout<<first_digit+last_digit<<"\n";
	}
	return 0;
}