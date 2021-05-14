#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,X;
		cin>>N>>X;
		vector<int>A(N);
		vector<int>B(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		B = A;
		sort(B.begin(), B.end());
		int cnt = 0;
		if(A != B)
		{
			int i = 0;
		}
		cout<<cnt<<endl;

	}
	return 0;
}
