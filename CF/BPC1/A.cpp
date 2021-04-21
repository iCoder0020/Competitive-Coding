#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	string N;
	cin>>N;
	int x = 0;
	int y = N.length();
	if(y>=2)
	{
		x = N[y-1]-'0';
		x += 2*(N[y-2]-'0'); 
	}
	else
		x = N[0]-'0';
	switch(x%4)
	{
		case 0:
			cout<<4<<endl;
			break;
		case 1:
			cout<<0<<endl;
			break;
		case 2:
			cout<<0<<endl;
			break;
		case 3:
			cout<<0<<endl;
	}
	return 0;
}
