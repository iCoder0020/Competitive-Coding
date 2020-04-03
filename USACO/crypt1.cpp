/*
ID: ishansa2
PROG: crypt1
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("crypt1.out");
ifstream fin("crypt1.in");
	
int num_digits_provided, digit_set[9];
int i,j,k,l,m,n1,n2,n3,n4,n5,check_p1,check_p2,check_finalp,p1,p2,finalp;
int count=0;

int digits(int n)
{
	int digit=0;
	while(n!=0)
	{
		n/=10;
		digit++;
	}
	return digit;
}

int check_digits(int n,int q)
{
	int rem;
	int c=0;
	int d=digits(n);
	while(n!=0)
	{
		rem=n%10;
		for(int p=0;p<num_digits_provided;p++)
		{
				if(rem==digit_set[p])
				{
					c++;
				}
		}
		n/=10;
	}
	if(c==d&&d==q)
	{
		return 1;
	}
	return 0;
}

int main()
{
	fin>>num_digits_provided;
	for(i=0;i<num_digits_provided;i++)
	{
		fin>>digit_set[i];
	}
	for(i=0;i<num_digits_provided;i++)
	{
		for(j=0;j<num_digits_provided;j++)
		{
			for(k=0;k<num_digits_provided;k++)
			{
				for(l=0;l<num_digits_provided;l++)
				{
					for(m=0;m<num_digits_provided;m++)
					{
						n1=digit_set[i];
						n2=digit_set[j];
						n3=digit_set[k];
						n4=digit_set[l];
						n5=digit_set[m];
						check_p1=0;
						check_p2=0;
						check_finalp=0;
						p1=n5*(n1*100+n2*10+n3);
						p2=n4*10*(n1*100+n2*10+n3);
						finalp=p1+p2;
						check_p1=check_digits(p1,3);
						check_p2=check_digits(p2/10,3);
						check_finalp=check_digits(finalp,4);
						if(check_p1==1&&check_p2==1&&check_finalp==1)
						{
							count++;
						}
					}
				}
			}
		}
	}
	fout<<count<<"\n";
	return 0;
}