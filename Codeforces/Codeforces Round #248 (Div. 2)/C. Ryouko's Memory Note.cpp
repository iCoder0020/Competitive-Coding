/*
ID: iCoder0020
PROG: Ryouko's Memory Note
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long li;

li find_median(vector<li> A)
{
	sort(A.begin(), A.end());
	return A[(A.size())/2];
}

int main()
{
	int N,M;
	cin>>N>>M;
	li A[M];
	map<li, vector<li>> MAP;
	li sum = 0;
	li ans;
	for(int m = 0; m<M; m++)
	{
		cin>>A[m];
	}
	for(int m = 0; m<M; m++)
	{
		if(m-1>=0)
		{
			if(A[m] != A[m-1])
			{
				MAP[A[m]].push_back(A[m-1]);
			}
		}
		if(m+1<M)
		{
			if(A[m] != A[m+1])
			{
				MAP[A[m]].push_back(A[m+1]);
			}
		}
		if(m > 0)
		{
			sum += abs(A[m] - A[m-1]);
		}
	}
	ans = sum;
	for(auto it: MAP)
	{
		li temp = sum;
		li median = find_median(it.second);
		for(auto it2: it.second)
		{
			temp = temp - abs(it.first - it2) + abs(median - it2);
		}
		ans = min(ans, temp);
	}
	cout<<ans<<endl;
	return 0;
}