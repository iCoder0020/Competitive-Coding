#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,G,B;
		cin>>N>>G>>B;
		int N_min = N/2 + (N%2);
		int days;
		if(G>=N_min)
			days = N;
		else if(N_min%G == 0)
			days = (N_min/G)*(G+B)-B;
		else
			days = (N_min/G)*(G+B) + N_min%G;
		cout<<max(N, days)<<endl;
	}
	return 0;
}

