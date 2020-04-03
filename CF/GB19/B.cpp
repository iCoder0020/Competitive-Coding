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
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int idx = -1;
		for(int n = 0; n<N-1; n++)
		{
			if(abs(A[n] - A[n+1])>=2)
				idx = n;
		}
		if(idx == -1)
			cout<<"NO";
		else
		{
			cout<<"YES"<<endl;
			cout<<idx+1<<" "<<idx+2;
		}
		cout<<endl;
	}
	return 0;
}
