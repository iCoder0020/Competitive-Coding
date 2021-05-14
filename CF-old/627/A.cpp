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
		sort(A, A+N);
		bool poss = true;
		for(int n = 1; n<N; n++)
		{
			if((A[n]-A[0])%2 == 1)
			{
				poss = false;
				break;
			}
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
