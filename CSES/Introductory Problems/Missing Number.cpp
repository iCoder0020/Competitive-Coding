#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int sum = (N*(N+1))/2;
	for(int n = 0; n<N-1; n++)
	{
		int x;
		cin>>x;
		sum -= x;
	}
	cout<<sum<<endl;
	return 0;
}
