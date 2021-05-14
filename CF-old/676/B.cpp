#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<vector<char>>g(N, vector<char>(N,'0'));
		for(int n = 0; n<N; n++)
			for(int m = 0; m<N; m++)
				cin>>g[n][m];
		set<pair<int,int>>S;
		char a = g[0][1];
		char b = g[1][0];
		char c = g[N-1][N-2];
		char d = g[N-2][N-1];
		if(a == b && c == d)
		{
			if(a == c)
			{
				S.insert({0,1});
				S.insert({1,0});
			}
		}
		else if(a == b)
		{
			if(c == a)
				S.insert({N-1,N-2});
			if(d == a)
				S.insert({N-2,N-1});
		}
		else if(c == d)
		{
			if(a == c)
				S.insert({0,1});
			if(b == c)
				S.insert({1,0});
		}
		else
		{
			S.insert({1,0});
			if(a == c)
				S.insert({N-1,N-2});
			else
				S.insert({N-2,N-1});
		}
		cout<<S.size()<<endl;
		for(pair<int,int> p: S)
			cout<<p.first+1<<" "<<p.second+1<<endl;
	}	
	return 0;
}
