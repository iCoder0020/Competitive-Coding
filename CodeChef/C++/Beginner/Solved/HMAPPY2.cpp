/*
ID: ishan_sang
PROG: HMAPPY2
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		li N,A,B,K;
		cin>>N>>A>>B>>K;
		li lcm = (A*B)/(__gcd(A,B));
		li solved_A = N/A - (N/lcm);
		li solved_B = N/B - (N/lcm);
		if(solved_A + solved_B >= K)
		{
			cout<<"Win"<<endl;
		}
		else
		{
			cout<<"Lose"<<endl;
		}
	}
	return 0;
}