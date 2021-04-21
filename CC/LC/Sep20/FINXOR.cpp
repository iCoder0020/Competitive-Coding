#include <bits/stdc++.h>

using namespace std;

#define int long long

void print(int a, int b)
{
	cout<<a<<" "<<b<<endl;
}

int32_t main()
{
	int TC;
	cin>>TC;
	int read;
	while(TC--)
	{
		int N;
		cin>>N;
		int X[20], Y[20];
		int S,q;
		print(1,(1<<20));
		cin>>q;
		S = q - ((1<<20)*N);
		for(int i = 0; i<19; i++)
		{
			print(1,(1<<i));
			cin>>q;
			X[i] = (q-S+((1<<i)*N))/((1<<(i+1)));
			Y[i] = N-X[i];
		}
		int ans = 0;
		int sum = 0;
		for(int i = 0; i<20; i++)
		{
			if(i==19)
				Y[i] = (S-sum)/(1<<i);
			else
				sum += (Y[i]*(1<<i));
			if(Y[i]&1)
				ans+=(1<<i);
		}		
		print(2,ans);
		cin>>read;
		if(read!=1)
			break;
	}
	return 0;
}