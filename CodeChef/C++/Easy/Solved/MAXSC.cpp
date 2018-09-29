/*
ID: ishan_sang
PROG: MAXSC
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	bool got_ans;
	long long int sum;
	int k;
	for(int t = 0; t<T; t++)
	{
		got_ans = false;
		cin>>N;
		long long int A[N][N];
		long long int A_max[N];
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				cin>>A[i][j];
			}
			sort(A[i], A[i]+N);
		}
		k = 0;
		A_max[k] = A[N-1][N-1];
		for(int i = N-2; i>=0; i--)
		{
			for(int j = N-1; j>=0; j--)
			{
				if(A[i][j] < A_max[k])
				{
					k++;
					A_max[k] = A[i][j];
					break;
				}
				if(j == 0)
				{
					cout<<"-1\n";
					got_ans = true;
					break;
				}
			}
			if(got_ans)
			{
				break;
			}				
		}
		if(!got_ans)
		{
			sum = 0;
			for(int i = 0; i<N; i++)
			{
				sum += A_max[i];
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}