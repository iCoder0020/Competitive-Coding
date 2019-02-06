/*
ID: iCoder0020
PROG: 100 - The 3n + 1 problem
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

#define N_MAX 10000000

li dp[N_MAX] = {0};

int main()
{
	dp[1] = 1;
	for(li n = 2; n<=1000000; n++)
	{
		li temp = n;
		while(1)
		{
			dp[n]++;
			if(temp%2 == 1)
			{
				temp = 3*temp+1;
				if(temp < N_MAX && dp[temp]!=0)
				{
					dp[n] += dp[temp];
					break;
				}
			}
			else
			{
				temp = temp>>1;
				if(temp < N_MAX && dp[temp]!=0)
				{
					dp[n] += dp[temp];
					break;
				}
			}
		}
	}
	int a,b;
	while(cin>>a>>b)
	{
		int maxm = 0;
		for(int x = min(a,b); x<=max(a,b); x++)
		{
			if(dp[x] > maxm)
			{
				maxm = dp[x];
			}
		}
		cout<<a<<" "<<b<<" "<<maxm<<endl;
	}
	return 0;
}