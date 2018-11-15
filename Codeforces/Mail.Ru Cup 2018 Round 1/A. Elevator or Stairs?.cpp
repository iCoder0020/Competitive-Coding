/*
ID: iCoder0020
PROG: Elevator or Stairs?
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int X,Y,Z,T1,T2,T3;
	int stair_time, elevator_time;
	cin>>X>>Y>>Z>>T1>>T2>>T3;
	stair_time = abs(X-Y)*T1;
	elevator_time = (abs(X-Z) + abs(Y-X))*T2 + 3*T3;
	if(stair_time < elevator_time)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	return 0;
}