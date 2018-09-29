/*
ID: iCoder0020
PROG: Bon Appétit
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int not_eaten;
	cin>>N>>not_eaten;
	int A[N];
	int paid;
	int share = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n != not_eaten)
		{
			share+=A[n];
		}
	}
	cin>>paid;
	share/=2;
	if(share == paid)
	{
		cout<<"Bon Appetit\n";
	}
	else
	{
		cout<<paid - share<<"\n";
	}
	return 0;
}