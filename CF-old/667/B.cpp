#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A,B,X,Y,N;
		int Ac, Bc, Nc;
		cin>>A>>B>>X>>Y>>N;
		Ac = A, Bc = B, Nc = N;
		if(A-X + B-Y <=N)
			A = X, B = Y;
		else
		{
			if(X == 1 && A-X<=N)
				N-=(A-X), A = 1;
			if(Y == 1 && B-Y<=N)
				N-=(B-Y), B = 1;
			// cout<<A<<" "<<B<<" "<<N<<endl;
			if(A<B || (A==B && X<=Y))
			{
				if(A-X<=N)
					N-=(A-X), A = X;
				else
					A -= N, N = 0;
				B = max(B-N,Y);
			}
			else
			{
				if(B-Y<=N)
					N-=(B-Y), B = Y;
				else
					B -= N, N = 0;
				A = max(A-N,X);
			}
			// cout<<A<<" "<<B<<" "<<N<<endl;
		}
		int ans1 = A*B, ans2, ans3;

		A = Ac, B = Bc, N = Nc;
		int p = max(X, A-N);
		N -= (A-p);
		A = p;
		B = max(Y,B-N);
		ans2 = A*B;

		A = Ac, B = Bc, N = Nc;
		int q = max(Y, B-N);
		N -= (B-q);
		B = q;
		A = max(X,A-N);
		ans3 = A*B;

		cout<<min({ans1,ans2,ans3})<<endl;
	}
	return 0;
}
