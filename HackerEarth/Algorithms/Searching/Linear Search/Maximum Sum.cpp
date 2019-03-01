/*
ID: icoder_0020
PROG: Maximum Sum
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int cnt = 0;
	long long int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] >= 0)
		{
			cnt++;
			sum += A[n];
		}
	}
	if(cnt == 0)
	{
		sort(A, A+N);
		cout<<A[N-1]<<" "<<1<<endl;
	}
	else
	{
		cout<<sum<<" "<<cnt<<endl;
	}
	return 0;
}
