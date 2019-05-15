/*
ID: iCoder0020
PROG: Make Them Equal
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	set<int> S;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		S.insert(A[n]);
	}	
	bool possible = true;
	int K = 0;
	sort(A, A+N);
	if(S.size() > 3)
	{
		possible = false;
	}
	else if(S.size() == 2)
	{
		if(((A[N-1] - A[0])%2) == 0)
			K = (A[N-1] - A[0])/2;
		else
			K = A[N-1]-A[0];
	}
	else
	{
		for(int n = 0; n<N-1; n++)
		{
			if(A[n+1]-A[n] == 0)
				continue;
			else
			{
				if(K == 0)
					K = A[n+1]-A[n];
				else if(K != A[n+1] - A[n])
					possible = false;
			}

		}
	}
	if(possible)
		cout<<K;
	else
		cout<<-1;
	cout<<endl;
	return 0;
}