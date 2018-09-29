/*
ID: iCoder0020
PROG: Highly divisible triangular number
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 1000

struct pair
{
	int index;
	int triangular_number;
};

int main()
{
	int T;
	int n;
	vector <pair> V;
	V.push_back(0,1);
	for
	for(int i = 1; i<=N_MAX/2; i++)
	{
		for(int j = 1; i*j<=N_MAX; j++)
		{
			count_factors[i*j-1]++;
		}
	}
	for(n = 0; n<N_MAX; n++)
	{
		cout<<n+1<<" "<<count_factors[n]<<"\n";
	}
	int N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		n = 0;
		cin>>N;
		while(count_factors[n])
	}
	return 0;
}