/*
ID: iCoder0020
PROG: Sasha and His Trip
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N,V;
	cin>>N>>V;
	if(V >= N)
	{
		cout<<N-1<<endl;
	}
	else
	{
		int cost = V;
		int fuel = V-1;
		for(int i = 2; i<N; i++)
		{
			if(fuel >= N-i)
			{
				break;
			}
			else
			{
				int fuel_taken = min(V-fuel, N-i-fuel);
				fuel += fuel_taken;
				cost += fuel_taken*(i);
			}
			fuel--;
		}
		cout<<cost<<endl;
	}
	return 0;
}