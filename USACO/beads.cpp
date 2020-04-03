/*
ID: ishansa2
PROG: beads
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
	ofstream fout("beads.out");
    	ifstream fin("beads.in");
	int n,a_l,a_r,ans[350],ans_max=2,i,j,k;
	char bead_s[352],bead_n[701];
	fin>>n;
	fin>>bead_s;
	for(i=0;i<n;i++)
	{
		bead_n[i]=bead_s[i];
		bead_n[n+i]=bead_s[i];
	}
	bead_n[n+i]='/0';
	for(i=0;i<n;i++)
	{
		a_l=0;
		a_r=0;
		j=i-1;
		if(bead_n[j]!='w')
		{
			while((j>=0)&&((bead_n[j]==bead_n[i-1])||(bead_n[j]=='w')))
			{
				a_l++;	
				j--;
			}
		}
		if(bead_n[j]=='w')
		{
			k=j;
			while(bead_n[k]=='w')
			{
				k--;
			}
			while((j>=0)&&((bead_n[j]==bead_n[k])||(bead_n[j]=='w')))
			{
				a_l++;	
				j--;
			}
		}
		j=i;
		while((j<(2*n))&&((bead_n[j]==bead_n[i])||(bead_n[j]=='w')))
		{
			a_r++;
			j++;
		}
		ans[i]=a_l+a_r;
		if(ans[i]>n)
		{
			ans[i]=n;
		}
		if(ans[i]>ans_max)
		{
			ans_max=ans[i];
		}	
	}
	fout<<ans_max<<"\n";
	return 0;
}