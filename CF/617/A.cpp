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
		int A[N];
		int even = 0;
		int odd = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]&1)
				odd++;
			else
				even++;
		}
		if(even == N || (odd == N && (N%2 == 0)))
			cout<<"NO";
		else
			cout<<"YES";
		cout<<endl;
	}
	return 0;
}
