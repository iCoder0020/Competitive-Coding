#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int sum = 0;
	for(int n = 2; n<N; n++)
	{
		int x = (N/n);
		sum += 4*(x*(x+1)/2 - 1);
	}
	cout<<sum<<endl;
	return 0;
}
