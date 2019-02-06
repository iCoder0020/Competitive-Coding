/*
ID: iCoder0020
PROG: Lunar New Year and Cross Counting
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	char mat[N][N];
	int count = 0;
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cin>>mat[i][j];
		}
	}
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(i-1>=0 && i+1<N && j-1>=0 && j+1<N)
			{
			if(mat[i][j] == 'X' && mat[i-1][j-1] == 'X' && mat[i+1][j+1] == 'X' && mat[i+1][j-1] == 'X' && mat[i-1][j+1] == 'X')
				{
					count++;
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}