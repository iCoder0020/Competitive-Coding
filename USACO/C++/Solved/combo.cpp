/*
ID: ishansa2
PROG: combo
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("combo.out");
ifstream fin("combo.in");

int N,J1,J2,J3,M1,M2,M3;
int i,j,k;
int count = 0;

int get_number(int n)
{
	if(n<=0)
	{
		n+=N;
	}
	if(n>N)
	{
		n-=N;
	}
	if(n<1||n>N)
	{
		n=get_number(n);
	}
	return n;
}

int check_neighbours(int n,int m)
{
	if(get_number(n-2)==m||get_number(n-1)==m||get_number(n)==m||get_number(n+1)==m||get_number(n+2)==m)
	{
		return 1;
	}
	return 0;
}


struct lock
{
	int check_1;
	int check_2;
	int check_3;
};

lock L[100];

int main()
{
	fin>>N;
	fin>>J1>>J2>>J3;
	fin>>M1>>M2>>M3;
	for(i=1;i<=N;i++)
	{
		L[i].check_1=0;
		L[i].check_2=0;
		L[i].check_3=0;
		if(check_neighbours(i,J1))
		{
			L[i-1].check_1=1;
		}
		if(check_neighbours(i,J2))
		{
			L[i-1].check_2=1;
		}
		if(check_neighbours(i,J3))
		{
			L[i-1].check_3=1;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(L[i-1].check_1==1)
		{
			for(j=1;j<=N;j++)
			{
				if(L[j-1].check_2==1)
				{
					for(k=1;k<=N;k++)
					{
						if(L[k-1].check_3==1)
						{
							count++;
						}
					}
				}
			}
		}
	}
	
	for(i=1;i<=N;i++)
	{
		if(check_neighbours(i,M1))
		{
			L[i-1].check_1+=2;
		}
		if(check_neighbours(i,M2))
		{
			L[i-1].check_2+=2;
		}
		if(check_neighbours(i,M3))
		{
			L[i-1].check_3+=2;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(L[i-1].check_1==2||L[i-1].check_1==3)
		{
			for(j=1;j<=N;j++)
			{
				if(L[j-1].check_2==2||L[j-1].check_2==3)
				{
					for(k=1;k<=N;k++)
					{
						if(L[k-1].check_3==2||L[k-1].check_3==3)
						{
							count++;
						}
					}
				}
			}
		}
	}
	
	for(i=1;i<=N;i++)
	{
		if(L[i-1].check_1==3)
		{
			for(j=1;j<=N;j++)
			{
				if(L[j-1].check_2==3)
				{
					for(k=1;k<=N;k++)
					{
						if(L[k-1].check_3==3)
						{
							count--;
						}
					}
				}
			}
		}
	}
	fout<<count<<"\n";
	return 0;
}
