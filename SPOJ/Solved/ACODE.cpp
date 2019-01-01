/*
ID: icoder_0020
PROG: ACODE
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	string num;
	while(1)
	{
		bool invalid = false;
		cin>>num;
		if(num == "0")
		{
			break;
		}
		else
		{
			li count[num.length()+1];
			count[0] = 1;
			count[1] = 1;
			if(num[0] == '0')
			{
				invalid = true;
			}
			for(int i = 2; i<=num.length(); i++)
			{
				if((num[i-1] == '0' && (num[i-2] != '1' && num[i-2] != '2')) || (invalid == true))
				{
					invalid = true;
					break;
				}
				else if(num[i-1] == '0')
				{
					count[i] = count[i-2];
				}
				else if(num[i-2] == '0')
				{
					count[i] = count[i-3];
				}
				else if(num[i-2] == '2' && (num[i-1] == '7' || num[i-1] == '8' || num[i-1] == '9')) 
				{
					count[i] = count[i-2];
				}
				else if(num[i-2]!='1' && num[i-2]!='2')
				{
					count[i] = count[i-1];
				}
				else
				{
					count[i] = count[i-1] + count[i-2];
				}
			}
			if(invalid)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<count[num.length()]<<endl;
			}
		}
	}
	return 0;
}