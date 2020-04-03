/*
ID: ishansa2
PROG: transform
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char old_board[10][10], new_board[10][10], tmp_board[10][10];
int n,i,j,k,l=0,check=0;

void horizontal_flip(char a[10][10],int n)
{
	if(n%2==0)
		l=1;
	for(i=0;i<n;i++)
	{
		for(j=0,k=n-1;j<(n/2),k>(n/2-l);j++,k--)
		{
			if(a[i][j]=='@'&&a[i][k]=='-')
			{
				a[i][j]='-';
				a[i][k]='@';
			}
			else if(a[i][k]=='@'&&a[i][j]=='-')
			{
				a[i][k]='-';
				a[i][j]='@';
			}
			else
			{
				continue;
			}
		}
	}		
}
void vertical_flip(char a[10][10],int n)
{
	if(n%2==0)
		l=1;
	for(i=0;i<n;i++)
	{
		for(j=0,k=n-1;j<(n/2),k>(n/2-l);j++,k--)
		{
			if(a[j][i]=='@'&&a[k][i]=='-')
			{
				a[j][i]='-';
				a[k][i]='@';
			}
			else if(a[k][i]=='@'&&a[j][i]=='-')
			{
				a[k][i]='-';
				a[j][i]='@';
			}
			else
			{
				continue;
			}
		}
	}
}
void transpose(char a[10][10],int n)
{
	char b[10][10];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];			
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=b[j][i];			
		}
	}
}

int main()
{
	ofstream fout("transform.out");
    	ifstream fin("transform.in");
	fin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			fin>>old_board[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			fin>>new_board[i][j];
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	vertical_flip(tmp_board,n);
	transpose(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"1"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}
	
	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	vertical_flip(tmp_board,n);
	horizontal_flip(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"2"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	horizontal_flip(tmp_board,n);
	transpose(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"3"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	horizontal_flip(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"4"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	horizontal_flip(tmp_board,n);
	vertical_flip(tmp_board,n);
	transpose(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"5"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	vertical_flip(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"5"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	transpose(tmp_board,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"5"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}

	check=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			tmp_board[i][j]=old_board[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if((tmp_board[i][j]==new_board[i][j])&&(i==n-1)&&(j==n-1))
			{
				fout<<"6"<<"\n";
				return 0;
			}
			else if(((i==n-1)&&(j==n-1))||(tmp_board[i][j]!=new_board[i][j]))
			{
				check=-1;
				break;
			}
		}
		if(check==-1)
			break;
	}


	fout<<"7"<<"\n";
	return 0;
}