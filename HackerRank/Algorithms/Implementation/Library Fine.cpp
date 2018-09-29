/*
ID: iCoder0020
PROG: Library Fine
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int D,M,Y;
	int d,m,y;
	cin>>D>>M>>Y;
	cin>>d>>m>>y;
	if(Y == y)
	{
		if(M == m)
		{
			if(D <= d)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<(D-d)*15<<"\n";
			}
		}
		else if(M > m)
		{
			cout<<(M-m)*500<<"\n";
		}
		else
		{
			cout<<"0\n";
		}
	}
	else if(Y > y)
	{
		cout<<"10000\n";
	}
	else
	{
		cout<<"0\n";
	}
	return 0;
}
