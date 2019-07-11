/*
ID: iCoder0020
PROG: Divide it!
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		int N;
		cin>>N;
		int cnt = 0;
		while(N > 1)
		{
			if(N%2 == 0)
				N/=2;
			else if(N%3 == 0)
				N = 2*(N/3);
			else if(N%5 == 0)
				N = 4*(N/5);
			else
				N = -1;
			cnt++;	
		}
		if(N == -1)
			cout<<"-1"<<endl;
		else
			cout<<cnt<<endl;

	}
	return 0; 
}