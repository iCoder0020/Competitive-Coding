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
	for(int t = 0; t<T; t++)
	{
		int a[3] = {0};
		bool first_element = false;
		bool possible = true;
		cin>>N;
		if(N>1)
		{
			for(int n = 0; n<N; n++)
			{
				cin>>num;
				if(num != 0 && num != 1 && num !=-1)
				{
					if(first_element == false)
					{
						first_element = true;
					}
					else
					{
						possible = false;
					}
				}
				else
				{
					a[num+1] ++;
				}
			}	
			if(a[0]>1 && a[2] == 0)
			{
				possible = false;
			}
			if(a[0]!=0 && first_element)
			{
				possible = false;
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
		else
		{
			cin>>num;
			cout<<"yes\n";
		}
	}
	return 0;
}