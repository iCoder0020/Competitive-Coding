/*
ID: iCoder0020
PROG: Between Two Sets
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int num=0,countA,countB;
	cin>>n>>m;
	int A[n],B[m];
	int A_max,B_min;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(i==0)
		{
			A_max=A[i];
		}
		if(A[i]>A_max)
		{
			A_max=A[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>B[i];
		if(i==0)
		{
			B_min=B[i];
		}
		if(B[i]<B_min)
		{
			B_min=B[i];
		}
	}
	for(int i=A_max;i<=B_min;i++)
	{
		countA=0;
		for(int j=0;j<n;j++)
		{
			if(i%A[j]==0)
				countA++;
		}
		countB=0;
		for(int j=0;j<m;j++)
		{
			if(B[j]%i==0)
				countB++;
		}
		if(countA==n && countB==m)
			num++;
	}
	cout<<num<<"\n";
	return 0;
}