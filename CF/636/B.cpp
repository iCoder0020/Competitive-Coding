#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		if(N%4 != 0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int mx = 1000000000-1;
		cout<<"YES"<<endl;
		for(int n = 0; n<N/2; n++)
		{
			if(n == N/2-1)
				cout<<mx-(N/2-1)<<" ";
			else
				cout<<2*n+2<<" ";
		}
		for(int n = 0; n<N/2; n++)
		{
			if(n == N/2-1)
				cout<<mx<<" ";
			else
				cout<<2*n+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
