/*
ID: ishan_sang
PROG: TLG
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int W,L=0;
	int A,B;
	int sumA=0,sumB=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>A>>B;
		sumA+=A;
		sumB+=B;
		if(sumA-sumB>L)
		{
			W=1;
			L=sumA-sumB;
		}
		if(sumB-sumA>L)
		{
			W=2;
			L=sumB-sumA;
		}
	}
	cout<<W<<" "<<L<<"\n";
	return 0;
}