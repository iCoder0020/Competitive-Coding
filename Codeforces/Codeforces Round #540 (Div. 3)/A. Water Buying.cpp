/*
ID: iCoder0020
PROG: Water Buying
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		li N,A,B;
		li cost = 0;
		cin>>N>>A>>B;
		if(A <= B/2)
		{
			cost = A*N;
		}
		else
		{
			cost = (N/2)*B + A*(N%2);
		}
		cout<<cost<<endl;
	}
	return 0;
}