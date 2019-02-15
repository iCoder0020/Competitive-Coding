/*
ID: iCoder0020
PROG: Digital root
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long int K,X;
		cin>>K>>X;
		cout<<(9*K-(9-X));
		cout<<endl;
	}
	return 0;
}