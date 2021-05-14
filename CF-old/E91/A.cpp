#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int minl[N], l[N];
		int minr[N], r[N];
		minl[0] = minr[N-1] = N+1;
		l[0] = r[N-1] = -1;
		for(int i = 1; i<N; i++)
		{
			if(A[i-1]<minl[i-1])
			{
				minl[i] = A[i-1];
				l[i] = i-1;
			}
			else
			{
				minl[i] = minl[i-1];
				l[i] = l[i-1];
			}
		}
		for(int i = N-2; i>=0; i--)
		{
			if(A[i+1]<minr[i+1])
			{
				minr[i] = A[i+1];
				r[i] = i+1;
			}
			else
			{
				minr[i] = minr[i+1];
				r[i] = r[i+1];
			}
		}
		// for(int i = 0; i<N; i++)
		// 	cout<<A[i]<<" "<<l[i]<<" "<<minl[i]<<" "<<r[i]<<" "<<minr[i]<<endl;
		int a,b,c;
		a = b = c = -1;
		for(int i = 0; i<N; i++)
		{
			if(A[i]>minl[i] && A[i]>minr[i])
				a = l[i]+1, b = i+1, c = r[i]+1;
		}
		if(a != -1)
		{
			cout<<"YES"<<endl;
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
