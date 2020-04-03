#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	string s,t;
	cin>>s>>t;
	int x1 = s[0]-'a', x2 = t[0]-'a', y1 = s[1]-'1', y2 = t[1]-'1';
	int c = 0;
	vector<string>moves;
	string x;
	while(x1!=x2 || y1!=y2)
	{
		x = "";
		if(x1<x2)
		{
			x+='R';
			x1++;
		}
		else if(x2<x1)
		{
			x+='L';
			x1--;
		}
		if(y1<y2)
		{
			x+='U';
			y1++;
		}
		else if(y2<y1)
		{
			x+='D';
			y1--;
		}
		moves.push_back(x);
		c++;
	}
	cout<<c<<endl;
	for(auto it: moves)
		cout<<it<<endl;
	return 0;
}
