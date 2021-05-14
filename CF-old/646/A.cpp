#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int x,n;
		cin>>n>>x;
		int a;
		int o = 0, e = 0;
		for(int i = 0; i<n; i++)
		{
			cin>>a;
			if(a&1)
				o++;
			else
				e++;
		}
		bool flag = false;
		for(int i = 0; i<=e; i++)
		{
			for(int j = 1; j<=o; j+=2)
			{
				if(i+j==x)
				{
					flag=true;
				}
			}
		}
		if(flag)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}
