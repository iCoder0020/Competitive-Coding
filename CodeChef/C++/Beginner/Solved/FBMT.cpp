/*
ID: ishan_sang
PROG: FBMT
LANG: C++
*/

#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	int T,N;
	string S1,S2,S;
	int n1,n2;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		n1 =0, n2 =0;
		cin>>N;
		for(int n = 0; n<N; n++)
		{
			cin>>S;
			if(n == 0)
			{
				S1 = S;
				n1++;
			}
			else
			{
				if(S != S1)
				{
					S2 = S;
					n2++;
				}
				else
				{
					n1++;
				}
			}
		}
		if(n1>n2)
		{
			cout<<S1<<"\n";
		}
		else if(n2>n1)
		{
			cout<<S2<<"\n";
		}
		else
		{
			cout<<"Draw\n";
		}
	}
	return 0;
} 