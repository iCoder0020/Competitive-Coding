/*
ID: iCoder0020
PROG: Cutting Out
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 200005

bool mysort(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
	return a.first.first>b.first.first;
}

int main()
{
	int N, K;
	cin>>N>>K;

	int temp;
	vector <pair<pair<int,int>,int>> A_count;

	for(int n = 0; n<N_MAX; n++)
	{
		A_count.push_back(make_pair(make_pair(0, n), 0));
	}
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		A_count[temp].first.first++;
	}
	sort(A_count.begin(), A_count.end(), mysort);
	
	for(int n = 0; n<K; n++)
	{
		
	}
	return 0;
}