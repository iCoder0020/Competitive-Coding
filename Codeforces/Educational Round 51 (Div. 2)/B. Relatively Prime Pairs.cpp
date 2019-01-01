/*
ID: iCoder0020
PROG: Relatively Prime Pairs
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	li L,R;
	cin>>L>>R;
	cout<<"YES"<<endl;
	for(li i = L; i<=R-1; i+=2)
	{
		cout<<i<<" "<<i+1<<endl;
	}
	return 0;
}