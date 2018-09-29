/*
ID: ishan_sang
PROG: FLOW010
LANG: C++                  
*/

#include <iostream>

using namespace std;

#define N_MAX 100000

int main()
{
	int T;
	cin>>T;
	char c;
	for(int t = 0; t<T; t++)
	{	
		cin>>c;
		if(c == 'b' || c == 'B')
		{
			cout<<"BattleShip";
		}
		else if(c == 'C' || c == 'c')
		{
			cout<<"Cruiser";
		}
		else if(c == 'D' || c == 'd')
		{
			cout<<"Destroyer";
		}
		else
		{
			cout<<"Frigate";
		}
		cout<<"\n";
	}
	return 0;
}