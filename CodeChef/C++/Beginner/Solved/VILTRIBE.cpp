/*
ID: ishan_sang
PROG: VILTRIBE
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	string S;
	int a,b,d;
	int l=1;
	cin>>T;
	char c;
	for(int i=0;i<T;i++)
	{
		a=0;
		b=0;
		cin>>S;
		for(int j=0;j<S.length();j+=l)
		{
			d=0;
			l=1;
			if(S[j]=='.')
				continue;
			else
			{
				c=S[j];
				if(S[j]=='A')
				{
					a++;
				}
				else
				{
					b++;
				}
				for(int k=j+1;k<S.length();k++,j++)
				{
					if(S[k]=='.')
					{
						d++;
						continue;
					}
					if(S[k]==c)
					{
						if(S[k]=='A')
						{
							a+=d+1;
						}
						else
						{
							b+=d+1;
						}
						d=0;
						continue;
					}
					else
					{
						if(S[k-1]!='.')
						{
							j=k-1;
						}
						break;
					}

				}
			}
		}
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
