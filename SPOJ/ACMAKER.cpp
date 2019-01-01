/*
ID: icoder_0020
PROG: ACMAKER
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int iwords;
	while(1)
	{
		cin>>iwords;
		if(iwords == 0)
		{
			break;
		}
		else
		{
			string S[iwords];
			for(int i = 0; i<iwords; i++)
			{
				cin>>S[i];
			}
			string input;
			vector <string> words;
			string temp;
			while(1)
			{
				cin>>input;
				if(input == "LAST CASE")
				{
					break;
				}
				else
				{
					for(int n = 0; n<input.length(); n++)
					{
						temp = "";
						while(input[n]!=' ' && input[n]!='\0' && input[n]!='\n')
						{
							temp += input[n];
						}
						for(int i = 0; i<iwords; i++)
						{
							if(temp == S[i])
							{
								break;
							}
							if(i == iwords-1)
							{
								words.push_back(temp);
							}
						}
					}
				}
			}
			for(auto it = words.begin(); it!=words.end(); it++)
			{
				cout<<*it<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}