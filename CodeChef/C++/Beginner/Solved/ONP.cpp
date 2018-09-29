/*
ID: ishan_sang
PROG: ONP
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;
	string S;
	for(int t=0; t<T; t++)
	{
		cin>>S;
		char ans[S.length()+1];
		int S_index=0;
		int temp_index;
		int ans_index=0;
		while(S_index != S.length()+1)
		{
			if(S[S_index]>='a' && S[S_index]<='z')
			{
				ans[ans_index]=S[S_index];
				S[S_index]='@';
				ans_index++;
			}
			if(S[S_index]==')')
			{
				temp_index = S_index;
				while(S[temp_index] != '(')
				{
					if(S[temp_index]=='*' || S[temp_index]=='/' || S[temp_index]=='+' || S[temp_index]=='-' || S[temp_index]=='^')
					{
						ans[ans_index] = S[temp_index];
						S[temp_index]='@';
						ans_index++;
					}
					temp_index--;
				}
				S[temp_index] = '@';
			}
			if(S_index == S.length())
			{
				temp_index = S_index;
				while(S[temp_index]!=')' && temp_index>0)
				{
					if(S[temp_index]=='*' || S[temp_index]=='/' || S[temp_index]=='+' || S[temp_index]=='-' || S[temp_index]=='^')
					{
						ans[ans_index] = S[temp_index];
						S[temp_index]='@';
						ans_index++;
					}
					temp_index--;
				}
				S[temp_index] = '@';
			}
			S_index++;
		}
		ans[ans_index] = '\0';
		cout<<ans<<"\n";
	}
}
