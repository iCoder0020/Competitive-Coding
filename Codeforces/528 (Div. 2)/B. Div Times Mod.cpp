/*
ID: iCoder0020
PROG: Div Times Mod
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int min_X = INT_MAX;
	vector <pair<int,int>> factors;
	for(int n = 1; n<=sqrt(N); n++)
	{
		if((n * (N/n) == N) && n<K)
		{
			factors.push_back(make_pair(n, N/n));
		}
	}
	for(auto it = factors.begin(); it!=factors.end(); it++)
	{
		for(int X = (*it).first*K; X<((*it).first+1)*K; X++)
		{
			if((X%K == (*it).second))
			{
				if(X < min_X)
				{
					min_X = X;
				}
			}
		}
		for(int X = (*it).second*K; X<((*it).second+1)*K; X++)
		{
			if((X%K == (*it).first))
			{
				if(X < min_X)
				{
					min_X = X;
				}
			}
		}
	}
	cout<<min_X<<endl;
	return 0;
}