/*
ID: iCoder0020
PROG: Two Shuffled Sequences
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
	vector<int>B;
	vector<int>C;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A, A+N);
	B.push_back(A[0]);
	bool ans = true;
	for(int n = 1; n<N; n++)
	{
		if(n>=2 && A[n] == A[n-1] && A[n-1] == A[n-2])
		{
			ans = false;
			break;
		}
		if(A[n] == A[n-1])
			C.push_back(A[n]);
		else
			B.push_back(A[n]);

	}
	if(ans)
	{
		sort(C.rbegin(), C.rend());
		cout<<"YES"<<endl;
		cout<<B.size()<<endl;
		for(auto it: B)
			cout<<it<<" ";
		cout<<endl<<C.size()<<endl;
		for(auto it: C)
			cout<<it<<" ";
		cout<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}