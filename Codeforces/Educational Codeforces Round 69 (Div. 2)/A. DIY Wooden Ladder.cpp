/*
ID: iCoder0020
PROG: DIY Wooden Ladder
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		if(N<3)
			cout<<0<<endl;
		else
		{
			sort(A, A+N, greater<int>());
			int max1 = A[0];
			int max2 = A[1];
			cout<<min(N-2, min(max1, max2)-1)<<endl;
		}
	}
	return 0;
}