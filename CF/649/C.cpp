#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N], B[N], NGE[N];
	int maxm = 1000000;
	vector<bool>C(N+1, false);
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n]>n+1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	NGE[N-1] = -1;
	for(int n = N-2; n>=0; n--)
	{
		if(A[n] == A[n+1])
			NGE[n] = NGE[n+1];
		else
			NGE[n] = n+1;
	}
	B[0] = 1-A[0];
	C[B[0]] = true;
	int k = A[0];
	int l = 2;
	for(int n = 1; n<N; n++)
	{
		if(A[n] != k)
		{
			B[n] = k;
			C[k] = true;
			if(NGE[n] != -1)
				k = A[NGE[n]];
		}
		else
		{
			if((NGE[n] == -1) || (l<A[NGE[n]]))
			{
				B[n] = l;
				C[l] = true;
				while(C[l])
					l++;
			}
			else
				B[n] = maxm;
		}
	}
	for(int n = 0; n<N; n++)
		cout<<B[n]<<" ";
	cout<<endl;
	return 0;
}
