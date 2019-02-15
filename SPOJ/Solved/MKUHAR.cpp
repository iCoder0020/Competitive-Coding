/*
ID: icoder_0020
PROG: MKUHAR
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> X;
vector <int> Y;

vector <pair<int,int>>small;
vector <pair<int,int>>big;

bool check(int N, int M, int meals)
{
	for(int n = 0; n<N; n++)
	{
		int to_buy = meals*X[n] - Y[n];
		int cost;
		int min_cost = INT_MAX;
		if(to_buy > 0)
		{
			for(int s = 0; s<=ceil(((double)to_buy)/small[n].first); s++)
			{
				cost = s*small[n].second;
				cost += ceil((double)(to_buy - s*small[n].first)/big[n].first)*big[n].second;
				min_cost = min(min_cost, cost);
			}
			M -= min_cost;
			if(M < 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N, M;
	cin>>N>>M;
	int a,b;
	for(int n = 0; n<N; n++)
	{
		cin>>a>>b;
		X.push_back(a);
		Y.push_back(b);
		cin>>a>>b;
		small.push_back({a,b});
		cin>>a>>b;
		big.push_back({a,b});
	}
	int min = 0;
	int max = 1e5;
	int meals;
	while(1)
	{
		meals = (min+max)/2;
		// cout<<meals<<endl;
		if(max - min <= 1)
		{
			if(check(N,M,max))
			{
				meals = max;
				break;
			}
			else
			{
				meals = min;
				break;
			}
		}
		else if(check(N,M,meals))
		{
			min = meals;
		}
		else
		{
			max = meals-1;
		}
	}
	cout<<meals<<endl;
	return 0;
}