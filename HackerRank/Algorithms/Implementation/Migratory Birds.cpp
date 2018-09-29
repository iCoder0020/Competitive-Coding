/*
ID: iCoder0020
PROG: Migratory Birds
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int count[5] = {0};
	for(int n=0; n<N; n++)
	{
		cin>>A[n];
		count[A[n]-1]++;
	}
	int max = 0;
	int max_id = 0;	
	for(int i=0; i<5; i++)
	{
		if(count[i]>max)
		{
			max = count[i];
			max_id = i;
		}
	}
	cout<<max_id+1<<"\n";
	return 0;
}