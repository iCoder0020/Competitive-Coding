/*
ID: iCoder0020
PROG: Forming a Magic Square
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int magic_squares[8][3][3] = {	{{4,9,2}, {3,5,7}, {8,1,6}},
									{{8,1,6}, {3,5,7}, {4,9,2}},
									{{2,9,4}, {7,5,3}, {6,1,8}},
									{{6,1,8}, {7,5,3}, {2,9,4}}
								};

	for(int i = 4; i<8; i++)
	{
		for(int row = 0; row<3; row++)
		{
			for(int col = 0; col<3; col++)
			{
				magic_squares[i][row][col] = magic_squares[i-4][col][row];
			}
		}
	}

	int matrix[3][3];
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			cin>>matrix[i][j];
		}
	}

	int cost;
	int min = 90;

	for(int i = 0; i<8; i++)
	{
		cost = 0;
		for(int row = 0; row<3; row++)
		{
			for(int col = 0; col<3; col++)
			{
				cost+=abs(matrix[row][col] - magic_squares[i][row][col]);
			}
		}
		if(cost < min)
		{
			min = cost;
		}
	}
	cout<<min<<"\n";
	return 0;
}