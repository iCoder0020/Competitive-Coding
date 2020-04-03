#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int> A(2*N);
		for(int n = 0; n<2*N; n++)
			cin>>A[n];
		sort(A.begin(), A.end());
		cout<<A[N]-A[N-1]<<endl;	
	}
	return 0;
}
