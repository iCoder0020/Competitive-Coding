#include <bits/stdc++.h>

using namespace std;

#define int long long

void q(int a, int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
}

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int maxm = 1, maxi = 1;
	int ans;
	for(int i = 1; i<N; i++)
	{
		q(i+1, maxi);
		cin>>ans;
		if(ans+1 <= maxm)
			maxi = i+1;
		maxm = max(maxm, ans+1);
	}
	A[maxi-1] = N;
	for(int i = 1; i<=N; i++)
	{
		if(i == maxi)
			continue;
		q(i, maxi);
		cin>>ans;
		A[i-1] = ans;
	}
	cout<<"! ";
	for(int i = 0; i<N; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}