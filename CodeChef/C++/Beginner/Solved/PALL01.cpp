/*
ID: ishan_sang
PROG: PALL01
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N,M,N_rev;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		M=N;
		N_rev = 0;
		while(N)
		{
			N_rev *= 10;
			N_rev += N%10;
			N /= 10;
		}
		if(M == N_rev)
		{
			cout<<"wins";
		}
		else
		{
			cout<<"losses";
		}
		cout<<"\n";
	}
	return 0;
}