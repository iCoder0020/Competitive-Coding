/*
ID: iCoder0020
PROG: Equalize the Array
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int count[100]={0};
	int max = 0;
	for(int i = 0; i<N; i++)
	{
		cin>>A[i];
		count[A[i]-1]++;
		max = (max>count[A[i]-1])?max:count[A[i]-1];
	}
	for(int i = 1; i<100; i++)
	{
		if(count[i-1] != count[i])
		{
			cout<<N-max<<"\n";
			break;
		}
		if(i == 99)
		{
			cout<<N-1<<"\n";
		}
	}
	return 0;
}