/*
ID: iCoder0020
PROG: Death Note
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long int li;

int main()
{
	li N,M;
	cin>>N>>M;
	li num;
	li pages_turned;
	li sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>num;
		sum += num;
		pages_turned = sum/M;
		cout<<pages_turned<<" ";
		sum -= (sum/M)*M;
	}
	cout<<"\n";
	return 0;
}