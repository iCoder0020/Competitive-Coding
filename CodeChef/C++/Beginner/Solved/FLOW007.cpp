/*
ID: ishan_sang
PROG: FLOW007
LANG: C++                  
*/

#include <iostream>

using namespace std;

int reverse_number(int N)
{
	int N_rev = 0;
	while(N > 0)
	{
		N_rev *= 10;
		N_rev += N%10;
		N /= 10;
	}
	return N_rev;
}

int main()
{
	int T,N,S;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		cout<<reverse_number(N)<<"\n";
	}
	return 0;
}