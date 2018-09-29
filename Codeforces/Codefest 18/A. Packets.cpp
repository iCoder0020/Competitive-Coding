/*
ID: iCoder0020
PROG: Packets
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int M;
	cin>>M;
	for(int n = 1; n<=30; n++)
	{
		if(pow(2,n)>=M+1)
		{
			cout<<n<<"\n";
			return 0;
		}
	}
	return 0;
}