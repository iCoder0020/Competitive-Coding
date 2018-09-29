/*
ID: ishan_sang
PROG: RRJOKE
LANG: C++                  
*/

#include <iostream>

using namespace std;

int XOR_upto_N(int N)
{
	switch(N&3)
	{
		case 0:
			return N;
		case 1:
			return 1;
		case 2:
			return N + 1;
		case 3:
			return 0;
	}
}

int main()
{
	int T, N, tmp;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		for(int j = 0; j<2*N; j++)
		{
			cin>>tmp;
		}
		cout<<XOR_upto_N(N)<<"\n";
	}
	return 0;
}