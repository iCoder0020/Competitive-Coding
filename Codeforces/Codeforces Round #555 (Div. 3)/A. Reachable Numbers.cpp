/*
ID: iCoder0020
PROG: Reachable Numbers
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int X;
	cin>>X;
	set<int>S;
	S.insert(X);
	while(1)
	{
		X++;
		while(X%10 == 0)
			X/=10;
		auto it = S.find(X);
		if(it!=S.end())
			break;
		else
			S.insert(X);
	}
	cout<<S.size()<<endl;
	return 0;
}