#include <bits/stdc++.h>

using namespace std;

#define int long long
#define NM 100002
int32_t main()
{
	int TC;
	cin>>TC;
	vector<bool>primes(NM, true);
	for(int i = 2; i<=NM; i++)
	{
		for(int j = 2; i*j<=NM; j++)
			primes[i*j] = false;
	}
	while(TC--)
	{
		int N;
		cin>>N;
		int X = 1;
		if(!primes[N])
		{
			while(1)
			{
				if(!primes[X] && primes[X+N-1])
					break;
				X++;
			}
		}
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				if(i == j)
					cout<<X<<" ";
				else
					cout<<1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
