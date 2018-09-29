/*
ID: ishan_sang
PROG: CLFIBD
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;
	string S;
	int new_count;
	for(int t = 0; t<T; t++)
	{
		int count_alphabets[26]={0};
		int new_set[26]={-1};
		new_count = 0;
		cin>>S;
		for(int i = 0; i<S.length(); i++)
		{
			count_alphabets[(int)(S[i]-'a')]++;
		}
		sort(count_alphabets, count_alphabets+26);
		for(int i = 0; i<26; i++)
		{
			if(count_alphabets[i] != 0)
			{
				new_set[new_count] = count_alphabets[i];
				new_count++;
			}
		}
		if(new_count<3)
		{
			cout<<"Dynamic\n";
		}
		else
		{
			for(int i = 2; i<new_count; i++)
			{
				if(new_set[i] != new_set[i-1] + new_set[i-2])
				{
					cout<<"Not\n";
					break;
				}
				if((new_set[i] == new_set[i-1] + new_set[i-2]) && (i == new_count-1))
				{
					cout<<"Dynamic\n";
				}
			}
		}
	}

	return 0;
}