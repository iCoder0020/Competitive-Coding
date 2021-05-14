#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<int> L(M);
	for(int m = 0; m<M; m++)
		cin>>L[m];
	int suffix[M];
	suffix[M-1] = L[M-1];
	for(int m = M-2; m>=0; m--)
		suffix[m] = suffix[m+1]+L[m];
	int i = 1,j = L[0];
	int P[M] = {0};
	bool poss = true;
	for(int m = 0; m<M; m++)
	{
		// cout<<i<<" "<<j<<endl;
		if(suffix[m]+j<N || i+L[m]>N)
		{
			poss = false;
			break;
		}
		if(m == 0)
			continue;
		if(m == M-1)
		{
			P[m] = N-suffix[m];
		}
		else
		{
			if(suffix[m+1]+i+L[m] >= N)
			{
				P[m] = i;
				i++;
				j = P[m]+L[m];
			}
			else if(suffix[m+1]+j+L[m] >= N)
			{
				P[m] = j;
				i = j+1;
				j = P[m]+L[m];
			}
		}
	}
	if(poss)
	{
		for(int m = 0; m<M; m++)
			cout<<P[m]+1<<" ";
		cout<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
