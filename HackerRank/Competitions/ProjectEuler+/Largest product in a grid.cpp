/*
ID: iCoder0020
PROG: Largest product in a grid
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[20][20];
	int product[4];
	int max_product = 0;
	for(int i = 0; i<20; i++)
	{
		for(int j = 0; j<20; j++)
		{
			cin>>A[i][j];
		}
	}
	for(int i = 0; i<20; i++)
	{
		for(int j = 0; j<20; j++)
		{
			for(int k = 0; k<4; k++)
			{
				product[k] = 1;
			}
			if(A[i][j]!=0)
			{
				if(j<=16 && i>=3)
				{
					for(int k = 0; k<4; k++)
					{
						product[0]*=A[i-k][j+k];
					}
					max_product = (max_product>product[0])?max_product:product[0];
				}
				if(j<=16)
				{
					for(int k = 0; k<4; k++)
					{
						product[1]*=A[i][j+k];
					}
					max_product = (max_product>product[1])?max_product:product[1];
				}
				if(i<=16 && j<=16)
				{
					for(int k = 0; k<4; k++)
					{
						product[2]*=A[i+k][j+k];
					}
					max_product = (max_product>product[2])?max_product:product[2];
				}
				if(i<=16)
				{
					for(int k = 0; k<4; k++)
					{
						product[3]*=A[i+k][j];
					}
					max_product = (max_product>product[3])?max_product:product[3];
				}
			}
		}
	}	
	cout<<max_product<<"\n";
	return 0;
}