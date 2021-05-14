#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int start, int a, int b, int l, int r)
{
	int x = start + b-a;
	if(x<l || x>r)
		return false;
	if(l == r && ((a>0) || (b>0)))
		return false;
	return true;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x,y,x1,y1,x2,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		if(check(x, a, b, x1, x2) && check(y, c, d, y1, y2))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}
