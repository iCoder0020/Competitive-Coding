/*
ID: icoder_0020
PROG: Min-Max
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

typedef long long int li;

int main()
{
	int N;
	cin>>N;
	li A[N];
	li min = INT_MAX;
	li max = 0;
	li sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] > max)
		{
			max = A[n];
		}
		if(A[n] < min)
		{
			min = A[n];
		}
		sum += A[n];
	}
	cout<<sum-max<<" "<<sum-min<<endl;
	return 0;
}
