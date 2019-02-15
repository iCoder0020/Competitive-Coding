/*
ID: iCoder0020
PROG: Minimum Integer
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int Q;
	cin>>Q;
	for(int q = 0; q<Q; q++)
	{
		int L,R,D;
		cin>>L>>R>>D;
		if(D<L)
		{
			cout<<D<<endl;
		}
		else
		{
			cout<<R+(D-R%D)<<endl;
		}
	}
	return 0;
}