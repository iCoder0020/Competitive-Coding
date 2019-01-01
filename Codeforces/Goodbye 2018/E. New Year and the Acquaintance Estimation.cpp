/*
ID: iCoder0020
PROG: New Year and the Acquaintance Estimation
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 998244353

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector <int> degree(N);
	for(int n = 0; n<N; n++)
	{
		cin>>degree[n];
	}
	sort(degree.rbegin(), degree.rend());
	
	return 0;
}