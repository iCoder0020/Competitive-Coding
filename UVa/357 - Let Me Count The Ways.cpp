/*
ID: iCoder0020
PROG: 357 - Let Me Count The Ways
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

#define N_MAX 30005

li dp[N_MAX] = {0};

int main()
{
	int N;

	int coins[5] = {1, 5, 10, 25, 50};

	dp[0] = 1;
			
	for(int j = 0; j<5; j++)
	{
		for(int n = coins[j]; n<N_MAX; n++)
		{
			dp[n] += dp[n - coins[j]];
		}
	}

	while(cin>>N)
	{
		if(dp[N] == 1)
		{
			cout<<"There is only 1 way to produce "<<N<<" cents change."<<endl;
		}
		else
		{
			cout<<"There are "<<dp[N]<<" ways to produce "<<N<<" cents change."<<endl;
		}
	}
	return 0;
}