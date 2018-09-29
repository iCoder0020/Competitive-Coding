/*
ID: ishan_sang
PROG: CUTBOARD
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N,M;
	for(int t = 0; t<T; t++)
	{	
		cin>>N>>M;
		cout<<(N-1)*(M-1)<<"\n";
	}
	return 0;
}