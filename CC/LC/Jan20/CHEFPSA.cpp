#include <bits/stdc++.h>

using namespace std;

#define int long long

#define MOD 1000000007

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(2*N);
		for(int n = 0; n<2*N; n++)
			cin>>A[n];
		sort(A.begin(), A.end());
		cout<<MOD<<endl;
	}	
	return 0;
}