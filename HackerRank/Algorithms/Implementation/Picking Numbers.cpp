/*
ID: iCoder0020
PROG: Picking Numbers
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int count[100] = {0};
	int sum;
	int max = 2;
	int num;
	for(int n = 0; n<N; n++)
	{
		cin>>num;
		count[num]++;
	}
	for(int i = 0; i<99; i++)
	{
		sum = count[i] + count[i+1];
		if(sum > max)
		{
			max = sum;
		}
	}
	cout<<max<<"\n";
	return 0;
}