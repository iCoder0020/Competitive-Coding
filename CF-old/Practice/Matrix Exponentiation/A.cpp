#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	double P;
	cin>>N>>P;
	double ans = 1.0;
	while(N)
	{
		if(N&1)
			ans = ans*(1-P) + (1-ans)*P;
		P = P*(1-P) + (1-P)*P;
		N = N>>1;
	}	
	cout<<setprecision(10)<<fixed<<ans<<endl;
	return 0;
}
