/*
ID: ishan_sang
PROG: NW1
LANG: C++                  
*/

#include <iostream>
 
using namespace std;
 
int main()
{
	int T;
	cin>>T;
	string day[7] = {"mon", "tues", "wed", "thurs", "fri", "sat", "sun"};
	int day_count[7];
	int first_day;
	int days;
	string s;
	for(int t = 0; t<T; t++)
	{
		cin>>days;
		cin>>s;
		for(int j = 0; j<7; j++)
		{
			if(s == day[j])
			{
				first_day = j;
			}
			day_count[j] = 0;
		}
		for(int j = 0; j<days; j++)
		{
			day_count[(first_day+j)%7]++;
		}
		for(int j = 0; j<7; j++)
		{
			cout<<day_count[j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 