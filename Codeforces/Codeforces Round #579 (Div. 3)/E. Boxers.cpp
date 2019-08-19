/*
ID: iCoder0020
PROG: Boxers
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
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A, A+N);
	set<int>S;
	for(int n = 0; n<N; n++)
	{
		if(A[n]-1>0 && S.find(A[n]-1) == S.end())
			S.insert(A[n]-1);
		else if(S.find(A[n]) == S.end())
			S.insert(A[n]);
		else
			S.insert(A[n]+1);
	}
	cout<<S.size()<<endl;
	return 0; 
}