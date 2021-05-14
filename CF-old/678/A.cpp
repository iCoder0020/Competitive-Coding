#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int sum = accumulate(A.begin(), A.end(), 0);
		if(sum == M)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
