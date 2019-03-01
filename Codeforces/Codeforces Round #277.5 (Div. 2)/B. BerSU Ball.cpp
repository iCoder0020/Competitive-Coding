/*
ID: iCoder0020
PROG: BerSU Ball
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	cin>>M;
	int B[M];
	for(int m = 0; m<M; m++)
		cin>>B[m];
	sort(A, A+N);
	sort(B, B+M);

	int i,j;
	int count = 0;

	i = 0;
	j = 0;

	while(1)
	{
		if(i == N || j == M)
		{
			break;
		}
		if(abs(A[i] - B[j]) <= 1)
		{
			count++;
			i++;
			j++;
		}
		else if(A[i] < B[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	cout<<count<<endl;
	return 0;
}