/*
ID: ishan_sang
PROG: CHEFSTLT
LANG: C++                  
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;
	string S1, S2;
	int min, max;
	for(int t = 0; t<T; t++)
	{
		cin>>S1>>S2;
		min = 0;
		max = S1.length();
		for(int i = 0; i<S1.length(); i++)
		{
			if(S1[i] != S2[i] && S1[i] != '?' && S2[i] != '?')
			{
				min++;
			}
			if(S1[i] == S2[i] && S1[i] != '?' && S2[i] != '?')
			{
				max--;
			}
		}
		cout<<min<<" "<<max<<"\n";
	}
	return 0;
}