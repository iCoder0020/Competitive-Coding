/*
ID: iCoder0020
PROG: Kangaroo
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int x1,v1,x2,v2;
	cin>>x1>>v1;
	cin>>x2>>v2;
	if(v2>=v1)
	{
		cout<<"NO"<<"\n";
		return 0;
	}
	else
	{
		while(x2>=x1)
		{
			x1+=v1;
			x2+=v2;
			if(x1==x2)
			{
				cout<<"YES"<<"\n";
				return 0;
			}
		}
		cout<<"NO"<<"\n";
	}	
	return 0;
}