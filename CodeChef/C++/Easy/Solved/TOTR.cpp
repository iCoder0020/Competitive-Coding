/*
ID: ishan_sang
PROG: TOTR
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	string line;
	map <char, char> char_chart;
	for(int i = 0; i<26; i++)
	{
		char_chart[(char)(97+i)] = S[i];
	}
	for(int i = 0; i<N; i++)
	{
		cin>>line;
		for(int j = 0; j<line.length(); j++)
		{
			if(line[j] == '_')
			{
				cout<<" ";
				continue;
			}
			if((int)line[j]>=65 && (int)line[j]<=90)
			{
				cout<<(char)(toupper(char_chart[tolower(line[j])]));
				continue;
			}
			if((int)line[j]>=97 && (int)line[j]<=122)
			{
				cout<<char_chart[line[j]];
				continue;
			}
			cout<<line[j];
		}
		cout<<"\n";
	}
	return 0;
}