/*
ID: iCoder0020
PROG: Merge it!
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
		int a = 0, b = 0, c = 0;
		int ans = 0;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]%3 == 0)
				a++;
			else if(A[n]%3 == 1)
				b++;
			else
				c++;
		}
		ans = a;
		if(b < c)
		{
			ans += b;
			ans += (c-b)/3;
		}
		else
		{
			ans += c;
			ans += (b-c)/3;
		}
		cout<<ans<<endl;
	}
	return 0; 
}