/*
ID: ishan_sang
PROG: ICPC16B
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	int num;
	bool possible, one, first_element;
	int count_minus_one;
	for(int t = 0; t<T; t++)
	{
		count_minus_one = 0;
		one = false;
		possible = true;
		first_element = false;
		cin>>N;
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num == -1)
			{
				count_minus_one++;
			}
			if(num == 1)
			{
				one = true;
			}
			if(num!=0 && num!=1 && num!=-1)
			{
				if(first_element == false)
				{
					first_element = true;
				}
				else
				{
					possible = false;
					break;
				}
			}
		}
		if(count_minus_one)
		{
			if(first_element)
			{
				possible = false;
			}
			else
			{
				if(count_minus_one > 1)
				{
					if(one == false)
					{
						possible = false;
					}
				}
			}
		}
		if (possible == false)
		{
			cout<<"no\n";
		}
		else
		{
			cout<<"yes\n";
		}
	}
	return 0;
}