#include <bits/stdc++.h>

using namespace std;

#define int long long

double calc_dist(pair<int,int>P, pair<int,int>Q)
{
	int x = (P.first-Q.first);
	int y = (P.second-Q.second);
	int d = x*x + y*y;
	return d;
}

int32_t main()
{
	int N;
	cin>>N;
	vector<pair<int,int>>v(N);
	for(int n = 0; n<N; n++)
		cin>>v[n].first>>v[n].second;
	map<int, int>MAP;
	map<int, int>MAP_ORIGINAL;
	int dist[N][N] = {0};
	for(int i = 0; i<N; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			dist[i][j] = dist[j][i] = calc_dist(v[i], v[j]);
			MAP_ORIGINAL[dist[i][j]]++;
		}
	}

	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}

	set<int>S;
	for(int i = 0; i<N; i++)
	{
		S.clear();
		MAP = MAP_ORIGINAL;
		for(int j = 0; j<N; j++)
		{
			if(j!=i)
			{
				S.insert(dist[i][j]);
				MAP[dist[i][j]]--;
				if(MAP[dist[i][j]] == 0)
					MAP.erase(dist[i][j]);
			}
		}
		bool flag = true;
		for(auto it: S)
		{
			if(MAP.find(it) != MAP.end())
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout<<"1"<<endl<<i+1<<endl;
			break;
		}
	}
	return 0;
}
