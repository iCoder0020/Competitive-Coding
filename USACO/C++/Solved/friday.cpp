/*
ID: ishansa2
PROG: friday
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int days(int year, int month)
{
	if(month==2)
	{	
		if((year%4==0&&year%100!=0)||(year%400==0))
		{
			return 29;
		}
		else 
		{
			return 28;
		}
	}
	if(month==4||month==6||month==9||month==11)
	{	
		return 30;
	}
	else
	{
		return 31;
	}
}

int main()
{
	ofstream fout("friday.out");
    ifstream fin("friday.in");
	int i=1,year,n,week_day[7],day,month;
	fin>>n;
	for(int j=0;j<7;j++)
	{
		week_day[j]=0;
	}
	for(year=1900;year<1900+n;year++)
	{
		for(month=1;month<=12;month++)		
		{
			for(day=1;day<=days(year,month);day++)
			{
				i++;
				if(day==13)
				{
					week_day[i%7]++;	
				}
			}		
		}
	}	
	for(i=0;i<6;i++)
	{
		fout<<week_day[i]<<" ";
	}
	fout<<week_day[i]<<"\n";
	return 0;
}