/*
ID: iCoder0020
PROG: Build a Contest
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int A[M];
	int count[N] = {0};
	int min_count = INT_MAX;
	int num;
	vector<int>index[N];
	for(int m = 0; m<M; m++)
	{
		cin>>A[m];
		count[A[m] - 1]++;
		index[A[m] - 1].push_back(m);
	}
	for(int n = 0; n<N; n++)
	{
		if(count[n] <= min_count)
		{
			min_count = count[n];
		}
	}

	int ans[M] = {0};

	for(int k = 0; k<min_count; k++)
	{
		int max_ind = 0;
		for(int n = 0; n<N; n++)
		{
			if(index[n][k] > max_ind)
			{
				max_ind = index[n][k];
			}
		}
		ans[max_ind] = 1;
	}

	for(int m = 0; m<M; m++)
	{
		cout<<ans[m];
	}
	cout<<endl;
	return 0;
}