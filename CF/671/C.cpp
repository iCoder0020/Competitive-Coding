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
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A.begin(), A.end());
		int s1 = 0, s2 =  0;
		int ans = 0;
		int s = 0;
		for(int r: A)
		{
			cout<<r<<" ";
			s+=r;
			s1+=r-X;
			s2+=abs(r-X);
		}
		if(s2 == 0)
			ans = 0;
		else if(s1 == 0)
			ans = 1;
		else
			ans = 2;
		cout<<ans<<endl;
	}
	return 0;
}