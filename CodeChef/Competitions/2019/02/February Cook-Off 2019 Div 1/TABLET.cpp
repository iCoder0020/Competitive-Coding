/*
ID: ishan_sang
PROG: TABLET
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,B;
		cin>>N>>B;
		int W,H,P;
		int max_area = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>W>>H>>P;
			if(P <= B)
			{
				if(W*H >= max_area)
				{
					max_area = W*H;
				}
			}
		}
		if(max_area == 0)
		{
			cout<<"no tablet";
		}
		else
		{
			cout<<max_area;
		}
		cout<<endl;
	}
	return 0;
}