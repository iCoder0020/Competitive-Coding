/*
ID: iCoder0020
PROG: Planning The Expedition
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int A[M];
	int food_type_count[100] = {0};
	int food_types = 0;
	int assumed_min;
	int max = 0;
	for(int m = 0; m<M; m++)
	{
		cin>>A[m];
		food_type_count[A[m]-1]++;
	}
	sort(food_type_count, food_type_count+100, greater<int>());

	for(int m = 0; m<100; m++)
	{
		if(food_type_count[m] == 0)
		{
			break;
		}
		food_types++;
	}
	int people_supported;
	if(food_types == 1)
	{
		max = food_type_count[0]/N;
	}
	else
	{
		for(assumed_min = 1; assumed_min<=100; assumed_min++)
		{	
			people_supported = 0;
			for(int j = 0; j<food_types; j++)
			{
				people_supported += food_type_count[j]/assumed_min; 
			}
			if(people_supported >= N)
			{
				max = (max>assumed_min)?max:assumed_min;
			}
		}
	}
	cout<<max<<"\n";
	return 0;
}