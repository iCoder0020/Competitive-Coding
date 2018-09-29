/*
ID: iCoder0020
PROG: Electronics Shop
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int B,N,M;
	cin>>B>>N>>M;
	int keyboard[N];
	int device[M];
	int cost = -1;
	int temp;
	for(int n = 0; n<N; n++)
	{
		cin>>keyboard[n];
	}
	for(int m = 0; m<M; m++)
	{
		cin>>device[m];
	}
	for(int i = 0; i<N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp = keyboard[i] + device[j];
			if(B == temp)
			{
				cost = B;
				break;
			}	
			if(B - temp>0)
			{
				if(cost < temp)
				{
					cost = temp;
				}
			}
		}
		if(cost == B)
		{
			break;
		}
	}
	cout<<cost<<"\n";
	return 0;
}