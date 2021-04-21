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
		int o = 0, e = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]&1)
				o++;
			else
				e++;
		}
		sort(A, A+N);
		bool x = false;
		for(int n = 1; n<N; n++)
			if(A[n]-A[n-1] == 1)
				x = true;
		if(o%2 == 0 || x)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
