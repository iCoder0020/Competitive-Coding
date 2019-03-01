/*
ID: ishan_sang
PROG: BFTT
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int count_threes;
	string N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		count_threes = 0;
		for(int n = 0; n<N.length(); n++)
		{
			if(N[n] == '3')
			{
				count_threes++;
			}
		}
		if(count_threes > 3)
		{
			int n = N.length()-1;
			if(N[n] != '9')
			{
				N[n] = (char)((int)(N[n]) + 1);
			}
			else
			{
				while(N[n] == '9')
				{
					N[n] = '0';
					n--;
				}
				N[n] = (char)((int)(N[n]) + 1);
			}
		}
		cout<<N<<"\n";
	}
	return 0;
}