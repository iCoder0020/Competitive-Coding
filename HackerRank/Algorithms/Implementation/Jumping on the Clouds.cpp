/*
ID: iCoder0020
PROG: Jumping on the Clouds
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int count = 0;
	for(int i = 0; i<N; i++)
	{
		cin>>A[i];
	}
	int index = 0;
	while(index < N)
	{
		if(index+2<N && A[index+2] == 0)
		{
			index+=2;
		}
		else
		{
			index++;
		}
		count++;
	}
	cout<<count-1<<"\n";
	return 0;
}