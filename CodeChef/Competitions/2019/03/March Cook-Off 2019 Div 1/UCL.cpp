/*
ID: ishan_sang
PROG: UCL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

struct score
{
	int points;
	int g_diff;
	bool operator<(const score &o) const
	{
		if(points < o.points)
		{
			return true;
		}
		else if(points == o.points)
		{
			return g_diff<o.g_diff;
		}
		else
		{
			return false;
		}
	}
};

bool mysort(pair<string, score> &p1, pair<string, score> &p2)
{
	return p1.second<p2.second;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		map<string, score> M;
		vector<pair<string, score>> V;
		for(int n = 0; n<12; n++)
		{
			string S1,S2, dump;
			int sc1, sc2;
			cin>>S1>>sc1>>dump>>sc2>>S2;
			if(M.find(S1) == M.end())
				M[S1] = {0,0};
			if(M.find(S2) == M.end())
				M[S2] = {0,0};
			if(sc1>sc2)
			{
				M[S1] = {M[S1].points + 3, M[S1].g_diff + sc1-sc2};
				M[S2] = {M[S2].points , M[S2].g_diff + sc2-sc1};
			}
			else if(sc1 == sc2)
			{
				M[S1] = {M[S1].points + 1, M[S1].g_diff};
				M[S2] = {M[S2].points + 1, M[S2].g_diff};	
			}
			else
			{
				M[S1] = {M[S1].points, M[S1].g_diff + sc1-sc2};
				M[S2] = {M[S2].points + 3, M[S2].g_diff + sc2-sc1};
			}
		}
		for(auto it: M)
		{
			V.push_back({it.first, it.second});
		}
		sort(V.begin(), V.end(), mysort);
		cout<<V[3].first<<" "<<V[2].first<<endl;
	}
	return 0;
}