/*
ID: ishan_sang
PROG: MAGICJAR
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
		int N;
		cin>>N;
		li A[N];
		li ans = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			ans += A[n]-1;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}