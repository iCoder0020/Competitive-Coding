#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		if(N%M == 0)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;	
	}
	return 0;
}

