/*
ID: iCoder0020
PROG: Breaking the Records
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int score[N];
	int min,max;
	int count_min = 0;
	int count_max = 0;
	for(int n=0; n<N; n++)
	{
		cin>>score[n];
		if(n==0)
		{
			min = score[n];
			max = score[n];
		}
		else
		{
			if(score[n]<min)
			{
				min = score[n];
				count_min++;
			}
			if(score[n]>max)
			{
				max = score[n];
				count_max++;
			}
		}
	}
	cout<<count_max<<" "<<count_min<<"\n";
	return 0;
}