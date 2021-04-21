#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int fact[N+1];
	fact[0] = 1;
	for(int n = 1; n<=N; n++)
		fact[n] = n*fact[n-1];
	int a = fact[N];
	int b = fact[N/2];
	int c = fact[(N/2)-1];
	int x = a/(b*b);
	int y = (c*c);
	cout<<(x*y)/2<<endl;
	return 0;
}
