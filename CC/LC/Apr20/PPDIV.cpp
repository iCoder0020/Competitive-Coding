#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define MAX 1000000000000000000

int power(int a, int b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	int c = power(a,b/2);
	if(b&1)
		return c*c*a;
	return c*c;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	int sqN = sqrt(MAX);
	vector<bool>weird_primes(sqN+1, true);
	int prev, curr;
	int cnt = sqN;
	for(int i = 2; i*i<=sqN; i++)
	{
		prev = 1;
		curr = i;
		while(1)
		{
			curr *= i;
			if(prev>curr || curr > sqN)
				break;
			weird_primes[curr] = false;
			cnt--;
			prev = curr;
		}
	}
	// T = 0;
	while(T--)
	{
		int N;
		cin>>N;		
		int sum = N%MOD;
		for(int i = 2; i*i<=N; i++)
		{
			if(!weird_primes[i])
				continue;
			prev = 1;
			curr = i;
			while(1)
			{
				curr *= i;
				if(prev>curr || curr > N)
					break;
				sum = (sum + ((N/curr)*curr)%MOD)%MOD;
				prev = curr;
			}
		}			
		cout<<sum<<"\n";
	}
	return 0;
}