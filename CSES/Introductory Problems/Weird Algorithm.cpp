#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	cout<<N<<" ";
	while(N!=1)
	{
		if(N&1)
			N = 3*N+1;
		else
			N>>=1;
		cout<<N<<" ";
	}
	cout<<endl;
	return 0;
}
