/*
ID: iCoder0020
PROG: Generate Login
LANG: C++                  
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S1, S2;
	int i;
	cin>>S1>>S2;
	cout<<S1[0];
	for (i = 0; i<S1.length()-1; i++)
	{
		if((int)(S1[i+1])>(int)(S2[0]))
		{
			cout<<S2[0];
			break;
		}
		if((int)(S1[i+1]) == (int)(S2[0]))
		{
			cout<<S2[0];
			break;
		}
		cout<<S1[i+1];
		if(i == S1.length()-2)
		{
			cout<<S2[0];
			break;
		}
	}
	if(S1.length() == 1)
	{
		cout<<S2[0];
	}
	cout<<"\n";
	return 0;
}