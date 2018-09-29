/*
ID: iCoder0020
PROG: Counting Valleys
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	char step;
	int progress = 0;
	int count = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>step;
		if(step == 'D')
		{
			if(progress == 0)
			{
				count++;
			}
			progress--;
		}
		else
		{
			progress++;
		}
	}
	cout<<count<<"\n";
	return 0;
}