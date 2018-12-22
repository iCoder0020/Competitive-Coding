/*
ID: iCoder0020
PROG: Petya and Origami
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin>>N>>K;
	long long int ans = (2*N)/K + (5*N)/K + (8*N)/K;
	if((2*N)%K != 0)
	{
		ans++;
	}
	if((5*N)%K != 0)
	{
		ans++;
	}
	if((8*N)%K != 0)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}