/*
ID: iCoder0020
PROG: Taum and B'day
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	long int b,w,bc,wc,z;
	long int min_cost;
	for(int t = 0; t<T; t++)
	{
		cin>>b>>w;
		cin>>bc>>wc>>z;
		if(bc+z<wc)
		{
			min_cost = b*bc + w*(bc+z);
		}
		else if(wc+z<bc)
		{
			min_cost = b*(wc+z) + w*wc;
		}
		else
		{
			min_cost = b*bc + w*wc;
		}
		cout<<min_cost<<"\n";
	}	
	return 0;
}