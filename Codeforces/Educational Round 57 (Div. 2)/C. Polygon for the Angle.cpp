/*
ID: iCoder0020
PROG: Polygon for the Angle
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	for(int n = 0; n<N; n++)
	{
		int ang;
		cin>>ang;
		int ans = -1;
		for(int i = 3; i<=360; i++)
		{
			for(int j = 1; j<=i-2; j++)
			{
				int temp = (180*j)/i;
				if(temp*i == 180*j && temp == ang)
				{
					ans = i;
				}
			}
			if(ans != -1)
			{
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}