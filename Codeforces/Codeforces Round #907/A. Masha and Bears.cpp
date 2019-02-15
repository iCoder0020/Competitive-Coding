/*
ID: iCoder0020
PROG: Masha and Bears
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int V[4],C[3][200],I_start[3], I_end[3];
	for(int i =0; i<3; i++)
	{
		for(int j = 0; j<200; j++)
		{
			C[i][j] = j+1;
		}
	}
	for(int i = 0; i<4; i++)
	{
		cin>>V[i];
		if(i < 3)
		{
			I_start[i] = V[i]-1;
			I_end[i] = 2*V[i]-1; 
		}
	}
	for(int i = I_start[2]; i<=I_end[2]; i++)
	{
		if(C[2][i]>=V[3] && C[2][i]<=2*V[3])
		{
			for(int j = I_start[1]; j<=I_end[1]; j++)
			{
				if(C[1][j]>2*V[3] && C[1][j]>C[2][i])
				{
					for(int k = I_start[0]; k<=I_end[0]; k++)
					{
						if(C[0][k]>C[1][j])
						{
							cout<<C[0][k]<<"\n"<<C[1][j]<<"\n"<<C[2][i]<<"\n";
							return 0;
						}
					}
				}
			}
		}
	}
	cout<<"-1\n";
	return 0;
}