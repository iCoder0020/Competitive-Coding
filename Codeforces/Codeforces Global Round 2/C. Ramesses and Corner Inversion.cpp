/*
ID: iCoder0020
PROG: Ramesses and Corner Inversion
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	int N, M;
	cin>>N>>M;
	int A[N][M];
	int B[N][M];
	bool possible = true;
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>A[n][m];
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>B[n][m];
	int sum;
	for(int n = 0; n<N; n++)
	{
		sum = 0;
		for(int m = 0; m<M; m++)
			if(A[n][m] != B[n][m])
				sum++;
		if(sum&1)
			possible = false;
	}
	for(int m = 0; m<M; m++)
	{
		sum = 0;
		for(int n = 0; n<N; n++)
			if(A[n][m] != B[n][m])
				sum++;
		if(sum&1)
			possible = false;
	}	
	if(!possible)
		cout<<"NO";
	else
		cout<<"YES";
	cout<<endl;
	return 0;
}