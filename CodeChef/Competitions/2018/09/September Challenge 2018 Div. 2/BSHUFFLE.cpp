/*
ID: ishan_sang
PROG: BSHUFFLE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	for(int n = 1; n<=N; n++)
	{
		cout<<n<<" ";
	}
	cout<<"\n";
	cout<<N<<" ";
	for(int n = 1;n<=N-1; n++)
	{
		cout<<n<<" ";
	}
	cout<<"\n";
	return 0;
}