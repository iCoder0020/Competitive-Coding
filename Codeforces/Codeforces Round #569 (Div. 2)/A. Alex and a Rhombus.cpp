/*
ID: iCoder0020
PROG: Alex and a Rhombus
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int dp[101];
	dp[1] = 1;
	for(int n = 2; n<=100; n++)
		dp[n] = 4*(n-2) + 4 + dp[n-1];
	int N;
	cin>>N;
	cout<<dp[N]<<endl;
	return 0; 
}