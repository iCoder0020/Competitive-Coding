/*
ID: iCoder0020
PROG: Salem and Sticks
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int i = 0; i<N; i++)
	{
		cin>>A[i];
	}
	long long int cost;
	long long int min_cost = INT_MAX;
	int min_T;
	for(int t = 1; t<=100; t++)
	{
		cost = 0;
		for(int n = 0; n<N; n++)
		{
			if(t != A[n])
			{
				cost += abs(t-A[n])-1;
			}
		}
		if(cost < min_cost)
		{
			min_T = t;
			min_cost = cost;
		}
	}
	cout<<min_T<<" "<<min_cost<<endl;
	return 0;
}