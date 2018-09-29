/*
ID: iCoder0020
PROG: Sock Merchant
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int C[100] = {0};
	int num;
	for(int n=0; n<N; n++)
	{
		cin>>num;
		C[num-1]++;
	}
	int count = 0;
	for(int n=0; n<100; n++)
	{
		count+=C[n]/2;
	}
	cout<<count<<"\n";
	return 0;
}