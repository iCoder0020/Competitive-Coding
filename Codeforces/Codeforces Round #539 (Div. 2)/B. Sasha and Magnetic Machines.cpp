/*
ID: iCoder0020
PROG: Sasha and Magnetic Machines
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int sum = 0;
	int min_sum;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		sum += A[n];
	}
	sort(A, A+N);
	min_sum = sum;
	for(int n = 1; n<N; n++)
	{
		for(int m = 2; m<=(A[n]/2); m++)
		{
			if(A[n] % m == 0)
			{
				min_sum = min(sum + m*A[0] + A[n]/m - A[n] - A[0], min_sum);
			}
		}
	}
	cout<<min_sum<<endl;
	return 0;
}