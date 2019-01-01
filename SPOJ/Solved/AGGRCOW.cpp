/*
ID: icoder_0020
PROG: AGGRCOW
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool check(lli X[], lli N, lli C, lli x)
{
	lli prev;
	lli cows = 1;
	prev = X[0];
	for(lli i = 0; i<N; i++)
	{
		if(X[i] - prev >= x)
		{
			cows++;
			prev = X[i];
			if(cows == C)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		lli N;
		lli C;
		cin>>N>>C;
		lli X[N];
		for(lli n = 0; n<N; n++)
		{
			cin>>X[n];
		}
		sort(X, X+N);

		lli min, mid, max;
		min = 0;
		max = X[N-1] - X[0];
		mid = (min+max)/2;
		if(check(X,N,C,max))
		{
			cout<<max<<"\n";
		}
		else
		{
			while(true)
			{
				if(check(X,N,C,min) && !check(X,N,C,min+1))
				{
					cout<<min<<"\n";
					break;
				}
				if(check(X,N,C,mid))
				{
					min = mid;
				}
				else
				{
					max = mid;
				}
				mid = (min+max)/2;
			}
		}
	}
	return 0;
}