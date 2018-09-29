/*
ID: ishansa2
PROG: milk2
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct farmer{
	int start;
	int end;
};

int checkState(int t, farmer f[], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (t >= f[i].start && t < f[i].end)
			return 1;
	}
	return -1;
}

int main(){
	ofstream fout("milk2.out");
    	ifstream fin("milk2.in");
	int num,i,j,max_end=0,min_start;
	farmer f[5000];
	fin>>num;
	for(i=0;i<num;i++)
	{
		fin>>f[i].start>>f[i].end;
		if(i==0)
			min_start=f[i].start;
		if(max_end<f[i].end)
		{
			max_end=f[i].end;
		}
		if(min_start>f[i].start)
		{
			min_start=f[i].start;
		}
	}	
	int active = 0, maxactive = 0, idle = 0, maxidle=0;
	int chk = 0;
	for (i = min_start; i <= max_end; i++) 
	{
		chk = checkState(i, f, num);
		if (chk == 1)
		{
			active++;
			if (maxidle < idle)
				maxidle = idle;
			idle=0;
		}
		if (chk == -1) 
		{
			idle++;
			if (maxactive < active)
				maxactive = active;
			active = 0;
		}
	}
	
	fout<<maxactive<<" "<<maxidle<<"\n";	
	return 0;
}