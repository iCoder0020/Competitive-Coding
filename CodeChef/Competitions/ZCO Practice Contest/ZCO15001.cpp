/*
ID: ishan_sang
PROG: ZCO15001
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int dp[N];
	for(int n = 0; n<N; n++)
	{
		dp[n] = 300;
	}
	vector <vector<int>> plength;
	vector <int> initial(1, 1);
	for(int n = 0; n<N; n++)
	{
		plength.push_back(initial);
	}
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int n = 0; n<N; n++)
	{
		int i = n-1;
		int j = n+1;
		int count = 1;
		while(i>=0 && j<N)
		{
			if(A[i] == A[j])
			{
				count+=2;
				plength[i].push_back(count);
			}
			else
			{
				break;
			}
			i--;
			j++;
		}
	}
	for(int n = 0; n<N-1; n++)
	{
		if(A[n] == A[n+1])
		{
			plength[n].push_back(2);
			int i = n-1;
			int j = n+2;
			int count = 2;
			while(i>=0 && j<N)
			{
				if(A[i] == A[j])
				{
					count+=2;
					plength[i].push_back(count);
				}
				else
				{
					break;
				}
				i--;
				j++;
			}
		}
	}
	dp[N-1] = 1;
	for(int n = N-2; n>=0; n--)
	{
		for(int m = 0; m<plength[n].size(); m++)
		{
			if(n + plength[n][m] >= N)
			{
				dp[n] = 1;
			}
			else
			{
				dp[n] = min(dp[n], 1 + dp[n + plength[n][m]]);
			}
		}
	}
	cout<<dp[0]<<endl;
	return 0;
}