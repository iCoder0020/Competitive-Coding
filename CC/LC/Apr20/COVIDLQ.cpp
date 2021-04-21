#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		bool poss = true;
		for(int i = 0; i<N; i++)
		{
			if(A[i] == 0)
				continue;
			for(int j = i+1; j<=min(N-1,i+5); j++)
			{
				if(A[j] == 0)
					continue;
				poss = false;
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