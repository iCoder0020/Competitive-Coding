#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A, A+N);
		int sum = 0;
		for(int n = N-1; n>=0; n--)
			sum = (sum + max(0LL, A[n]-(N-1-n)))%MOD;
		cout<<sum<<endl;
	}
	return 0;
}