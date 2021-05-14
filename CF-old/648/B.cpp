#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<int> A(N), B(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		for(int n = 0; n<N; n++)
			cin>>B[n];
		vector<int>ans = A;
		sort(ans.begin(), ans.end());
		int x = accumulate(B.begin(), B.end(), 0);
		
		if((A == ans) || (x != 0 && x != N))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}
