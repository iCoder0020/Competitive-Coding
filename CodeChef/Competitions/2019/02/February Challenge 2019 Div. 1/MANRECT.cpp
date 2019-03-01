/*
ID: ishan_sang
PROG: MANRECT
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		li ans1, ans2, ans3, ans4, ans5;
		cout<<"Q 0 0"<<endl;
		cin>>ans1;
		cout<<"Q 0 1000000000"<<endl;
		cin>>ans2;
		cout<<"Q 1000000000 1000000000"<<endl;
		cin>>ans3;
		cout<<"Q 1000000000 0"<<endl;
		cin>>ans4;
		cout<<"Q 0 "<<(ans1-ans2 + 1000000000)/2<<endl;
		cin>>ans5;
		li x1, x2, y1, y2;
		x1 = ans5;
		y1 = ans1 - x1;
		x2 = 1000000000 + y1 - ans4;
		y2 = 1000000000 + x1 - ans2;
		cout<<"A "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		int ans;
		cin>>ans;
		if(ans < 0)
		{
			break;
		}
	}
	return 0;
}