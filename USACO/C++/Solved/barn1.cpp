/*
ID: ishansa2
PROG: barn1
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("barn1.out");
ifstream fin("barn1.in");

int max_boards, total_stalls, stalls_occupied;
int gap_front=0, gap_rear=0, gap[200];
int i,j;

struct stall
{
	int stall_num;
	int state;
};

stall S[200];

void swap(int &a,int &b)
{
	a+=b;
	b=a-b;
	a-=b;
}

void set_stall_default()
{
	for(i=0;i<total_stalls;i++)
	{
		S[i].state=0;
		S[i].stall_num=i+1;
	}
}
	
void input()
{
	int n;
	for(i=0;i<stalls_occupied;i++)
	{
		fin>>n;
		for(j=0;j<total_stalls;j++)
		{
			if(S[j].stall_num==n)
			{
				S[j].state=1;
				break;
			}
		}
	}
}

void find_gaps1()
{
	for(i=0;i<total_stalls;i++)
	{
		if(S[i].state==0)
		{
			gap_front++;
		}
		else
			break;
	}
	for(i=0;i<total_stalls;i++)
	{
		if(S[total_stalls-i-1].state==0)
		{
			gap_rear++;
		}
		else
			break;
	}
	if(gap_front==total_stalls)
	{
		gap_rear=0;
	}
}

int find_next(int n)
{
	int i;
	for(i=n;i<total_stalls;i++)
	{
		if(S[i].state==1)
			return i;
	}
	return n-1;
}

void find_gaps2()
{
	int next;
	j=0;
	for(i=0;i<total_stalls;i++)
	{
		while(S[i].state==0&&i<total_stalls)
			i++;
		if(i<total_stalls)
		{
			next=find_next(i+1);
			gap[j]=S[next].stall_num-S[i].stall_num;
			j++;
		}
	}
}

void sort_gap()
{
	for(i=0;i<total_stalls-1;i++)
	{
		for(j=i+1;j<total_stalls;j++)
		{
			if(gap[i]<gap[j])
				swap(gap[i],gap[j]);
		}
	}
}

void find_ans()
{
	int sum=0;
	for(i=0;i<max_boards-1;i++)
	{
		sum+=gap[i]-1;
	}
	fout<<total_stalls-(gap_front+gap_rear+sum)<<"\n";
}

int main()
{
	fin>>max_boards;
	fin>>total_stalls;
	fin>>stalls_occupied;
	if(stalls_occupied<max_boards)
		fout<<stalls_occupied<<"\n";
	else
	{
		set_stall_default();
		input();
		find_gaps1();
		find_gaps2();
		sort_gap();
		find_ans();
	}
	return 0;
}