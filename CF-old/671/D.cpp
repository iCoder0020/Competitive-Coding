#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	vector<int>A(N);
	vector<int>B(N,0);
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A.begin(), A.end());
	int x = 0;
	for(int i = 1; i<N; i+=2)
		B[i] = A[x++];
	for(int i = 0; i<N; i++)
		if(B[i] == 0)
			B[i] = A[x++];
	int cnt = 0;
	for(int n = 1; n<N-1; n++)
		if(B[n] < B[n-1] && B[n] < B[n+1])
			cnt++;
	cout<<cnt<<endl;
	for(int v: B)
		cout<<v<<" ";
	cout<<endl;
	return 0;
}