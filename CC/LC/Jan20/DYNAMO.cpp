#include <bits/stdc++.h>

using namespace std;

#define int long long

void print(int x)
{
	cout<<x<<endl;
	cout.flush();
}

int32_t main()
{
	int T,N,A,B,C;
	cin>>T;
	vector<int> pow10(19, 1);
	for(int i = 1; i<19; i++)
		pow10[i] = pow10[i-1]*10;
	while(T--)
	{
		cin>>N;
		cin>>A;
		print(2*pow10[N]+A);
		cin>>B;
		print(pow10[N]-B);
		cin>>C;
		print(pow10[N]-C);
		cin>>N;
		if(N == -1)
			return 0;
	}
	return 0;
}