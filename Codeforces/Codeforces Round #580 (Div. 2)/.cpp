/*
ID: iCoder0020
PROG: Circle of Students
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int Q,N;
	cin>>Q;
	while(Q--)
	{
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		bool flag = true;
		if(N <= 2)
			cout<<"YES";
		else
		{
			int d;
			if(A[1] > A[0])
			{
				if(A[1] - A[0] == 1)
					d = 1;
				else
					d = -1;
			}
			else
			{
				if(A[1] - A[0] == -1)
					d = -1;
				else
					d = 1;
			}
			for(int n = 1; n<N-1; n++)
			{
				if(A[n+1] - A[n] == d)
					continue;
				else if(A[n+1] == N && A[n] == 1)
					continue;
				else if(A[n+1] == 1 && A[n] == N)
					continue;
				else
					flag = false;
			}
			if(flag)
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<endl;
	}
	return 0; 
}