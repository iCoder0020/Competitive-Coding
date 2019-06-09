/*
ID: iCoder0020
PROG: Another One Bites The Dust
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int ans = 2*C;
	if(A < B)
		ans += 2*A + 1;
	else if(A == B)
		ans += 2*A;
	else
		ans += 2*B + 1;
	cout<<ans<<endl;
	return 0;
}