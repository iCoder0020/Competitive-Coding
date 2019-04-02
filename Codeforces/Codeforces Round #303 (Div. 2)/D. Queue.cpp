/*
ID: iCoder0020
PROG: Queue
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int count = N;
	long long int sum = 0;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A, A+N);
	for(int n = 0; n<N; n++)
	{
		while(n<N && sum > A[n])
		{
			n++;
			count--;
		}
		sum += A[n];
	}
	cout<<count<<endl;
	return 0;
}