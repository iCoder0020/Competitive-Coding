/*
ID: iCoder0020
PROG: Views Matter
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int N,M;
	cin>>N>>M;
	long long int A[N];
	long long int required, total_sum;
	long long height;
	total_sum = 0;
	
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		total_sum += A[n];
	}
	if(N == 1)
	{
		cout<<"0\n";
	}
	else
	{
		sort(A, A+N);
		height = A[N-1];
		required = 0;
		for(int n = N-1; n>0; n--)
		{
			if(height > A[n-1] && A[n]!=A[n-1])
			{
				required += height - A[n-1];
				height = A[n-1];
			}
			else
			{
				if(height > 0)
				{
					height--;
				}
				required ++;
			}	
			if(n == 1)
			{
				if(height == 0)
				{
					required++;
				}
				else
				{
					required+=height;
					height = 0;
				}
			}
		}
		cout<<total_sum - required<<endl;
	}
	return 0;
}