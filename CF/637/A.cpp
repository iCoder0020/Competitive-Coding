#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		if(n*(a-b)<=c+d && n*(a+b)>=c-d)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}		
	return 0;
}
