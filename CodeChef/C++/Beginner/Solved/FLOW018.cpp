/*
ID: ishan_sang
PROG: FLOW018
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	unsigned long long int N, M, fact[20];
	cin>>T;
	for(int i = 0; i<20; i++)
	{
		fact[i] = 0;
	}
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		M = N;
		if(fact[N-1] == 0)
		{
			fact[N-1] = 1;
			while(M)
			{
				fact[N-1] *= M;
				M--;
			}
		}
		cout<<fact[N-1]<<"\n";
	}
	return 0;
}