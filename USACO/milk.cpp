/*
ID: ishansa2
PROG: milk
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("milk.out");
ifstream fin("milk.in");

int milk_required,num_farmers,cost[5000],available_units[5000];
int i,j,last_farmer_index;
int total_cost=0,units_from_last_farmer;

void swap(int &a,int &b)
{
	a+=b;
	b=a-b;
	a-=b;
}

void input_n_sort()
{
	for(i=0;i<num_farmers;i++)
	{
		fin>>cost[i]>>available_units[i];
	}
	for(i=0;i<num_farmers-1;i++)
	{
		for(j=i+1;j<num_farmers;j++)
		{
			if(cost[i]>cost[j])
			{
				swap(cost[i],cost[j]);
				swap(available_units[i],available_units[j]);
			}
		}
	}
}

int find_last_unit()
{
	for(i=0;i<num_farmers;i++)
	{
		milk_required-=available_units[i];
		if(milk_required==0)
		{
			last_farmer_index=i;
			return available_units[i];
		}
		else if(milk_required<0)
		{
			last_farmer_index=i;
			milk_required+=available_units[i];
			for(j=1;j<=available_units[i];j++)
			{
				milk_required--;
				if(milk_required==0)
				{
					return j;
				}
			}
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	fin>>milk_required;
	fin>>num_farmers;
	input_n_sort();
	units_from_last_farmer = find_last_unit();
	for(i=0;i!=last_farmer_index;i++)
	{
		total_cost+=available_units[i]*cost[i];
	}
	total_cost+=units_from_last_farmer*cost[i];
	fout<<total_cost<<"\n";
	return 0;
}