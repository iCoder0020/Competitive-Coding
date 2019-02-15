/*
ID: iCoder0020
PROG: Lunar New Year and Food Ordering
LANG: C++                  
*/

#include <bits/stdc++.h>

#define type first
#define rem second.first
#define cost second.second

typedef long long int li;

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	li A[N];
	li C[N];
	int index[N];
	li COST[M] = {0};
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int n = 0 ; n<N; n++)
	{
		cin>>C[n];
	}
	vector<pair<li,int>> sorted;
	for(int n = 0; n<N; n++)
	{
		sorted.push_back({C[n], n});
	}
	sort(sorted.begin(), sorted.end());
	for(int n = 0; n<N; n++)
	{
		index[n] = sorted[n].second;
	}
	int curr_index = 0;
	for(int m = 0; m<M; m++)
	{
		int T,D;
		cin>>T>>D;
		T--;
		if(A[T] >= D)
		{
			COST[m] = D*C[T];
			A[T] -= D;
		}
		else
		{
			D-=A[T];
			COST[m] = A[T]*C[T];
			A[T] = 0;
			while(D > 0)
			{
				if(curr_index < N)
				{
					if(A[index[curr_index]] >= D)
					{
						COST[m] += D*C[index[curr_index]];
						A[index[curr_index]] -= D;
						D = 0;
					}
					else
					{
						COST[m] += A[index[curr_index]]*C[index[curr_index]];
						D -= A[index[curr_index]];
						A[index[curr_index]] = 0;
						curr_index++;
					}
				}
				else
				{
					COST[m] = 0;
					break;
				}
			}
		}
	}
	for(int m = 0; m<M; m++)
	{
		cout<<COST[m]<<endl;
	}
	return 0;
}