/*
ID: iCoder0020
PROG: 108 - Maximum Sum
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int N ;
	cin>>N;
	li A[N][N];
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cin>>A[i][j];
		}
	}
	int x1,x2,y1,y2;
	li B[N][N];
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(j == 0)
			{
				B[i][j] = A[i][j];
			}
			else
			{
				B[i][j] = B[i][j-1] + A[i][j];
			}
		}
	}
	li max_sum = -1*INT_MAX;
	
	for(int y1 = 0; y1<N; y1++)
	{
		for(int y2 = y1; y2<N; y2++)
		{
			li max_local_sum = -1*INT_MAX;
			li sum = -1*INT_MAX;
			for(int n = 0; n<N; n++)
			{
				li temp =  B[n][y2]-B[n][y1]+A[n][y1];
				sum = max(sum + temp, temp);
				max_local_sum = max(sum, max_local_sum);
			}
			max_sum = max(max_local_sum, max_sum);
		}
	}
	cout<<max_sum<<endl;
	return 0;
}