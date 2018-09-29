/*
ID: ishan_sang
PROG: CHEFSUM
LANG: C++
*/

#include <iostream>

using namespace std;

int T;
long A,min_A,N,min_index;
int i,j;

void run()
{
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>N;
		for(j=0;j<N;j++)
		{
			cin>>A;
			if(j==0)
            {
                min_A=A;
                min_index=1;
            }
			if(A<min_A)
			{
				min_A=A;
				min_index=j+1;
			}
		}
		cout<<min_index<<"\n";
	}
}

int main()
{
	run();
	return 0;
}
