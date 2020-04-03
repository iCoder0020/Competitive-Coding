/*
ID: ishansa2
PROG: gift1
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int np,gift[10],num[10],per_person[10],balance[10];
int i,j,k,l;
char name[10][16],gift_giver[10][16],gift_receiver[10][16];

int main(){
	ofstream fout("gift1.out");
    	ifstream fin("gift1.in");
    	fin>>np;
	for(i=0;i<np;i++)
	{
		fin>>name[i];	
		balance[i]=0;
	}
	for(i=0;i<np;i++)
	{
		fin>>gift_giver[i];
		fin>>gift[i]>>num[i];
		if(num[i]==0)
		{
			continue;
		}
		per_person[i]=gift[i]/num[i];
		for(l=0;l<np;l++)
		{
			if(!strcmp(gift_giver[i],name[l]))
			{
				balance[l]=balance[l]+((-1)*gift[i])+(gift[i]%num[i]);	
			}
		}
		for(j=0;j<num[i];j++)
		{	
			fin>>gift_receiver[j];
			for(k=0;k<np;k++)
			{
				if(!(strcmp(gift_receiver[j],name[k])))
				{
					balance[k]+=per_person[i];
				}
			}
		}	
	}
	for(i=0;i<np;i++)
		fout<<name[i]<<" "<<balance[i]<<"\n";
	return 0;
}