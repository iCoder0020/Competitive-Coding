/*
ID: ishan_sang
PROG: DIGJUMP
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long
#define pb(x) push_back(x)

using namespace std;

int32_t main()
{
	string S;
	cin>>S;
	int N = S.length();
	vector<bool>check(10, false);
	vector<int> adj_list[10];
	vector<int> dis(N, -1);
	for(int n = 0; n<N; n++)
		adj_list[S[n]-'0'].pb(n);
	queue<int>Q;
	Q.push(0);
	dis[0] = 0;
	while(!Q.empty())
	{
		int ind = Q.front();
		if(!check[S[ind]-'0'])
		{
			for(auto it: adj_list[S[ind]-'0'])
				if(dis[it] == -1)
				{
					dis[it] = dis[ind] + 1;
					Q.push(it);
				}
			check[S[ind]-'0'] = true;
		}
		if(ind+1<N && dis[ind+1] == -1)
		{
			dis[ind+1] = dis[ind] + 1;
			Q.push(ind+1);
		}
		if(ind-1>=0 && dis[ind-1] == -1)
		{
			dis[ind-1] = dis[ind] + 1;
			Q.push(ind-1);
		}
		Q.pop();
	}
	cout<<dis[N-1]<<endl;
	return 0;
}