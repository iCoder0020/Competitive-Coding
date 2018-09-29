/*
ID: iCoder0020
PROG: Angry Professor
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int total;
	int min;
	int count;
	int num;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>total>>min;
		count = 0;
		for(int i = 0; i<total; i++)
		{
			cin>>num;
			if(num<=0)
			{
				count++;
			}
		}
		if(count < min)
		{
			cout<<"YES\n";
		}	
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}