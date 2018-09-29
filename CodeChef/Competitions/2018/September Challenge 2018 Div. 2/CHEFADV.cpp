/*
ID: ishan_sang
PROG: CHEFADV
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	long int N,M,X,Y;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M>>X>>Y;
		if(N == 1 || M == 1)
		{
			if(N == M)
			{
				cout<<"Chefirnemo\n";
			}
			else if(M>1 && (M-1)%Y == 0)
			{
				cout<<"Chefirnemo\n";
				
			}
			else if(N>1 && (N-1)%X == 0)
			{
				cout<<"Chefirnemo\n";
				
			}
			else
			{
				cout<<"Pofik\n";
			}
			continue;
		}
		if((N-1)%X == 0 && (M-1)%Y == 0)
		{
			cout<<"Chefirnemo\n";
		}
		else
		{
			if((N-2)%X == 0 && (M-2)%Y == 0)
			{
				cout<<"Chefirnemo\n";
				
			}
			else
			{
				cout<<"Pofik\n";
			}
		}
	}
	return 0;
}