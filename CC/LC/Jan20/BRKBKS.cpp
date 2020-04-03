#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int S,A,B,C;
		cin>>S>>A>>B>>C;
		if(S>=A+B+C)
			cout<<1;
		else if(S>=A+B || S>=B+C)	
			cout<<2;
		else
			cout<<3;
		cout<<endl;
	}
	return 0;
}