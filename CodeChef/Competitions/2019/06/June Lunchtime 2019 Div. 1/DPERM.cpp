/*
ID: ishan_sang
PROG: DPERM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N, D;
		cin>>N>>D;
		int A[N+1];
		map<int,int> M;
		bool poss = true;
		int cnt = -1;
		for(int n = 1; n<=N; n++)
		{
			cin>>A[n];
			M[A[n]] = n;
			if((A[n] - n)%D != 0)
				poss = false;
		}
		if(poss)
		{
			cnt = 0;
			for(int n = 1; n<=N; n++)
			{
				if(A[n] == n)
					continue;
				else
				{
					
					A[A[n]] = A[n];
					A[n] = n;
					for(int n = 1; n<=N; n++)
						cout<<A[n]<<" ";
					cout<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}