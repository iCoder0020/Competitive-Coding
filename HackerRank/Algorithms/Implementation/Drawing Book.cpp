/*
ID: iCoder0020
PROG: Drawing Book
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int P;
	cin>>N>>P;
	if(P == 1 || P == N || (P == N-1 && N%2 == 1))
	{
		cout<<"0\n";
	}
	else
	{
		int start = (P-1)/2 + (P-1)%2;
		int end = (N-P)/2 - (N%2 - 1)*(P%2);
		start<end?cout<<start<<"\n":cout<<end<<"\n";
	}
	return 0;
}