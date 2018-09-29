/*
ID: iCoder0020
PROG: Designer PDF Viewer
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int height[26];
	for(int i = 0; i<26; i++)
	{
		cin>>height[i];
	}
	string S;
	cin>>S;
	int max_height = 1;
	for(int j = 0; j<S.length(); j++)
	{
		if(height[S[j]-97] > max_height)
		{
			max_height = height[S[j]-97];
		}
	}
	cout<<S.length()*max_height<<"\n";
	return 0;
}