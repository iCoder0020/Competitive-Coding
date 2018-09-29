/*
ID: ishansa2
PROG: namenum
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int name_to_num(char a)
{
	switch(a)
	{
		case 'A':
		case 'B':
		case 'C':
		return 2;
		
		case 'D':
		case 'E':
		case 'F':
		return 3;
			
		case 'G':
		case 'H':
		case 'I':
		return 4;
		
		case 'J':
		case 'K':
		case 'L':
		return 5;
			
		case 'M':
		case 'N':
		case 'O':
		return 6;
		
		case 'P':
		case 'R':
		case 'S':
		return 7;
			
		case 'T':
		case 'U':
		case 'V':
		return 8;
		
		case 'W':
		case 'X':
		case 'Y':
		return 9;
			
		default:
		return 0;		
	}
}

long long input,my_num;
int i,j,k,count=0,names=0;
char name[5000][14], ans[5000][14];

int main()
{
	ofstream fout("namenum.out");
    ifstream fin("namenum.in");
	ifstream gin("dict.txt");
	fin>>input;
	for(i=0;gin>>name[i];i++)
	{
		names++;
	}
	for(i=0;i<names;i++)
	{
		my_num=0;
		for(k=0;name[i][k]!='\0';k++)
		{
			my_num=(my_num*10)+name_to_num(name[i][k]);
		}
		if(my_num==input)
		{
			for(j=0;name[i][j]!='\0';j++)
			{
				ans[count][j]=name[i][j];
			}
		count++;
		}
	}
	if(count==0)
	{
		fout<<"NONE\n";
	}
	else
	{
		for(i=0;i<count;i++)
		{
			fout<<ans[i]<<"\n";
		}	
	}
	return 0;
}