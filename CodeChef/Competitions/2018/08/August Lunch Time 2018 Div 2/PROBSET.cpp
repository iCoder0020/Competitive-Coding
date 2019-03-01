/*
ID: ishan_sang
PROG: PROBSET
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,M;
	char ch;
	int start;
	int one_count;
	int characters_left;
	bool invalid, weak;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		invalid = false;
		weak = false;
		for(int n = 0; n<N; n++)
		{
			one_count = 0;
			ch = 'a';
			characters_left = 1;
			while(characters_left)
			{
				cin>>ch;
				characters_left--;
				if(ch == 'c' && characters_left == 0)
				{
					start = 0;
					characters_left = 6 + M;
				}
				if(ch == 'w')
				{
					start = 1;
					characters_left = 4 + M;
				}
				if(ch == '1')
				{
					one_count++;
				}
			}
			if(start == 0 && one_count != M)
			{
				invalid = true;
			}
			if(start == 1 && one_count == M)
			{
				weak = true;
			}
		}
		if(invalid)
		{
			cout<<"INVALID\n";
		}
		else if(weak)
		{
			cout<<"WEAK\n";
		}
		else
		{
			cout<<"FINE\n";
		}
	}
	return 0;
}