/*
ID: ishan_sang
PROG: AMR15A
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T;
	int N;
	int num;
	int even_count = 0;
	int odd_count = 0;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num%2 == 0)
			{
				even_count++;
			}
			else
			{
				odd_count++;
			}
		}
		if(even_count>odd_count)
		{
			cout<<"READY FOR BATTLE";
		}
		else
		{
			cout<<"NOT READY"
		}
		cout<<"\n";
	}
	return 0;
}