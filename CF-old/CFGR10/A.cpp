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
		int A[N];
		set<int>S;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			S.insert(A[n]);
		}
		if(S.size() == 1)
			cout<<N;
		else
			cout<<1;
		cout<<endl;
	}
	return 0;
}
