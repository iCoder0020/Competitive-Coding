/*
ID: iCoder0020
PROG: Complete the Projects (easy version)
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

bool mysort(pair<int,int> &A, pair<int,int> &B)
{
	if(A.second == B.second)
		return A.first < B.first;
	else
		return A.second > B.second;
}


int32_t main()
{
	int N,R;
	cin>>N>>R;
	vector<pair<int,int>>jobs(N);
	for(int n = 0; n<N; n++)
		cin>>jobs[n].first>>jobs[n].second;
	sort(jobs.begin(), jobs.end(), mysort);
	for(auto it: jobs)
		cout<<it.first<<" "<<it.second<<endl;
	return 0; 
}