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
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A.begin(), A.end(), greater<int>());
		for(auto it: A)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}

