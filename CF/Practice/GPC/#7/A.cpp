#include <bits/stdc++.h>

using namespace std;

#define int long long

map<char,int>MAP;
set<int>vis;

void bt(vector<vector<int>>&v, int &ans, int bmask)
{
	if(vis.find(bmask)!=vis.end())
		return;
	vis.insert(bmask);
	bool done = true;
	for(int i = 0; i<5; i++)
	{
		int x = 0;
		for(int j = 0; j<5; j++)
		{
			if(v[i][j] == 1)
				x++;
		}
		if(x>1)
			done = false;
	}
	if(done)
	{
		int cnt = 0;
		for(int i = 0; i<10; i++)
			if(bmask&(1<<i))
				cnt++;
		ans = min(ans, cnt);
	}
	for(int i = 0; i<10; i++)
	{
		if(bmask&(1<<i))
			continue;
		bmask = bmask|(1<<i);
		bt(v,ans,bmask);
		bmask = bmask^(1<<i);
	}
}

int32_t main()
{
	int N;
	cin>>N;
	MAP['1'] = 0;
	MAP['2'] = 1;
	MAP['3'] = 2;
	MAP['4'] = 3;
	MAP['5'] = 4;
	MAP['R'] = 5;
	MAP['G'] = 6;
	MAP['B'] = 7;
	MAP['Y'] = 8;
	MAP['W'] = 9;
	vector<vector<int>>v(5, vector<int>(5,0));
	for(int n = 0; n<N; n++)
	{
		char c,x;
		cin>>c>>x;
		int b = MAP[c], a = MAP[x];
		v[a][b-5] = 1;
	}
	for(int i = 0; i<5; i++)
	{
		for(int j = 0; j<5; j++)
			cout<<v[i][j];
		cout<<endl;
	}
	int ans = 10;
	bt(v, ans, 0);
	cout<<ans<<endl;
	return 0;
}
