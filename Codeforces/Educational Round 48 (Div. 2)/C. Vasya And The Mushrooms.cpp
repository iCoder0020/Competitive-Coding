/*
ID: iCoder0020
PROG: Vasya And The Mushrooms
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int growth[2][N];
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cin>>growth[i][j];
		}
	}
	long int sum = 0;
	long int max;
	int t = 0;
	for(int j = 0; j<N; j++)
	{
		sum += t*growth[0][j];
		t++;
	}
	for(int j = N-1; j>=0; j--)
	{
		sum += t*growth[1][j];
		t++;
	}
	
	if(N>=2)
	{
		max = sum;
		sum = growth[1][0] + 2*growth[1][1];

		int current_i = 1;
		int current_j = 1;

		for(t = 3; t<2*N; t++)
		{
			if(current_i == 1)
			{
				if(current_j+1<N)
				{
					if(growth[0][current_j]<growth[1][current_j+1])
					{
						current_i = 0;
						sum += t*growth[current_i][current_j];
					}
					else
					{
						current_j++;
						sum += t*growth[current_i][current_j];
					}
				}
				else
				{
					current_i = 0;
					sum += t*growth[current_i][current_j];
					while(t<2*N)
					{
						current_j--;
						sum += t*growth[current_i][current_j];
						t++;
					}
				}
			}
			else
			{

			}
		}

		max = (max>sum)?max:sum;
	}
	cout<<max<<"\n";
	return 0;
}