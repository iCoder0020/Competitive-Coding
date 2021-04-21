#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int S = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		S += A[n];
	}
	if(S%3 != 0)
	{
		cout<<0<<endl;
		return 0;
	}
	int cnt = 0;
	int a = 0, b = 0;
	int s = 0;
	for(int n = 0; n<N; n++)
	{
		s+=A[n];
		if(3*s == S)
			a++;
		if(S == 0)
			cnt+=max(0LL,a-2);
		else if(3*s == 2*S)
			cnt+=a;
	}
	cout<<cnt<<endl;
	return 0;
}
