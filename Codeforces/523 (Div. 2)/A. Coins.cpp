/*
ID: iCoder0020
PROG: Coins
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N, S;
	cin>>N>>S;
	int ans = S/N;
	if(S%N != 0)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}