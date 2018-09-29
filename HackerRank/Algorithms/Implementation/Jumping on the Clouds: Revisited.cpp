/*
ID: iCoder0020
PROG: Jumping on the Clouds: Revisited
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int C[N];
	for(int n = 0; n<N; n++)
	{
		cin>>C[n];
	}
	int E =100;
	int position = 0;
	do
	{
		position = (position + K)%N;
		if(C[position] == 0)
		{
			E = E-1;
		}
		else
		{
			E = E-3;
		}
	}while(position != 0);
	cout<<E<<"\n";
	return 0;
}	