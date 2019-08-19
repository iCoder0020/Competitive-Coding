/*
ID: iCoder0020
PROG: Equal Rectangles
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int Q,N;
	cin>>Q;
	while(Q--)
	{
		cin>>N;
		map<int, int> sticks;
		for(int n = 0; n<4*N; n++)
		{
			int temp;
			cin>>temp;
			sticks[temp]++;
		}
		bool flag = true;
		int area = sticks.begin()->first * sticks.rbegin()->first;
		for(auto it: sticks)
			if((it.second)%2 == 1)
				flag = false;
		while(flag && sticks.size() != 0)
		{
			int x = sticks.begin()->first, y = sticks.rbegin()->first;
			int nx = sticks.begin()->second, ny = sticks.rbegin()->second;
			if(nx>=2 && ny>=2 && x*y == area)
			{
				sticks.begin()->second -= 2;
				if(sticks.begin()->second == 0)
					sticks.erase(x);
				sticks.rbegin()->second -= 2;
				if(sticks.rbegin()->second == 0)
					sticks.erase(y);
			}
			else
			{
				flag = false;
				break;
			}
		}
		if(!flag)
			cout<<"NO";
		else
			cout<<"YES";
		cout<<endl;
	}
	return 0; 
}