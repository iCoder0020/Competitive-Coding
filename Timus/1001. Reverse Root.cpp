/*
ID:266214DN
PROG: Reverse Root
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long double a;
	vector<double>root;
	while(cin>>a)
	{
		root.push_back(sqrt((long double)(a)));
	}
	for(int n = root.size()-1; n>=0; n--)
	{
		cout<<fixed<<setprecision(4)<<root[n]<<endl;
	}
	return 0;
}