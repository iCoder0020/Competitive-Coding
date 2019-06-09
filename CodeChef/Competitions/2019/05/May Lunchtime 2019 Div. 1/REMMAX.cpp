/*
ID: ishan_sang
PROG: REMMAX
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string N;
		cin>>N;
		int len = N.length();
		if(len == 1)
			cout<<N;
		else
		{
			int n = len-1;
			char c = (char)((int)(N[0])-1);
			for(n ; n>=0; n--)
			{
				if(N[n] != '9')
					break;	
			}
			if(n<=0)
				cout<<N;
			else if(c == '0')	
			{
				bool type = false;
				bool chg = false;

				for(n = 1; n<len; n++)
					if(N[n] != '0')
						break;
				if(n != len)
				{
					n++;
					for(n; n<len; n++)
						if(N[n] != '9')
							break;
					if(n == len)
						type = true;
				}

				if(type)
				{
					cout<<N;
				}
				else
				{
					for(n = 1 ; n<len-1; n++)
					{
						if(N[n] >= '1')
						{
							N[n+1] = '9';
							if(!chg)
								N[n]--;
							chg = true;
						}
					}
					if(!chg && N[len-1] == '0')
					{
						string T = "";
						while(n--)
							T += '9';
						cout<<T;
					}
					else
						cout<<N;
				}
			}
			else
			{
				n = len-1;
				string T = "";
				while(n--)
					T += '9';
				T = c + T;
				cout<<T;
			}
		}
		cout<<endl;
	}
    return 0;
}