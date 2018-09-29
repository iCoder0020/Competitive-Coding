/*
ID: ishan_sang
PROG: COMM3
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

struct point
{
	int X;
	int Y;
};

float distance(int X1, int Y1, int X2, int Y2)
{
	int diff_X = X2-X1;
	int diff_Y = Y2-Y1;
	return sqrt(diff_X*diff_X + diff_Y*diff_Y);
}

int main()
{
	int T;
	int R;
	point P[3];
	float dist[3];
	int count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		count = 0;
		cin>>R;
		cin>>P[0].X>>P[0].Y;
		cin>>P[1].X>>P[1].Y;
		cin>>P[2].X>>P[2].Y;
		for(int i = 0; i<3; i++)
		{
			dist[i] = distance(P[i].X, P[i].Y, P[(i+1)%3].X, P[(i+1)%3].Y);
			if(dist[i]<=R)
			{
				count++;
			}
		}
		if(count>=2)
		{
			cout<<"yes";
		}
		else
		{
			cout<<"no";
		}
		cout<<"\n";
	}
	return 0;
}