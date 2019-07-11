/*
ID: ishan_sang
PROG: FUZZYCON
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int A,B,C,X,Y,Z;
		cin>>A>>B>>C>>X>>Y>>Z;
		int p = abs(A-X);
		int q = abs(B-Y);
		int r = abs(C-Z);
		int s1 = (A&1) + (B&1) + (C&1);
		int s2 = (X&1) + (Y&1) + (Z&1);
		int ans = 0;
		if(p == 0 && q == 0 && r == 0)
			ans = 0;
		else if(A == 0 && B == 0 && C == 0)
		{
			if(s2 == 0 || s2 == 3)
				ans = 2;
			else
				ans = 1;
		}
		else
		{
			if(X == 0 && Y == 0 && Z == 0)
			{
				if(s1 == 0 || s1 == 3)
					ans = 2;
				else
					ans = 1;
			}
			else
			{
				if((p&1)!=(q&1) || (q&1)!=(r&1))
					ans = 1;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}