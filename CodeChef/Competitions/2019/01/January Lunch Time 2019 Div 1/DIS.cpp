/*
ID: ishan_sang
PROG: DIS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;	
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;

		long double A[N];
		long double B[N];

		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		for(int n = 0; n<N; n++)
		{
			cin>>B[n];
		}


		bool possible = true;

		long double d = A[N-1];
		
		if( ( fabs(A[0]) > 0.0000001) || (fabs(B[N-1]) > 0.0000001) || fabs(d-B[0])>0.0000001 )
		{
			possible = false;
		}
		
		for(int i = 0; i<N; i++)
		{
			if( (d > A[i] + B[i]) || (A[i] > d + B[i]) || (B[i] > d + A[i]) )
			{
				possible = false;
				break;
			}
		}

		if(possible)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}
	return 0;
}