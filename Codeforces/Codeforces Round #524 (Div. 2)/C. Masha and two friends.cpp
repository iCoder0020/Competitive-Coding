/*
ID: iCoder0020
PROG: Masha and two friends
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int ll;

ll total(ll X1, ll Y1, ll X2, ll Y2)
{
	if(X2>=X1 && Y2>=Y1)
	{
		return (X2-X1+1)*(Y2-Y1+1);
	}
	else
	{
		return 0;
	}
}

ll num_white(ll X1, ll Y1, ll X2, ll Y2)
{
	if(X2>=X1 && Y2>=Y1)
	{
		if((X1+Y1)%2==0)
		{
			return ((Y2-Y1+2)/2)*((X2-X1+2)/2) + ((Y2-Y1+1)/2)*((X2-X1+1)/2);
		}
		else
		{
			return total(X1,Y1,X2,Y2) - (((Y2-Y1+2)/2)*((X2-X1+2)/2) + ((Y2-Y1+1)/2)*((X2-X1+1)/2));
		}
	}
	else
	{
		return 0;
	}
}

ll num_black(ll X1, ll Y1, ll X2, ll Y2)
{
	if(X2>=X1 && Y2>=Y1)
	{
		if((X1+Y1)%2==1)
		{
			return ((Y2-Y1+2)/2)*((X2-X1+2)/2) + ((Y2-Y1+1)/2)*((X2-X1+1)/2);
		}
		else
		{
			return total(X1,Y1,X2,Y2) - (((Y2-Y1+2)/2)*((X2-X1+2)/2) + ((Y2-Y1+1)/2)*((X2-X1+1)/2));
		}
	}
	else
	{
		return 0;
	}
}


ll minm(ll a, ll b)
{
	return (a<b)?a:b;
}

ll maxm(ll a, ll b)
{
	return (a<b)?a:b;
}

int main()
{
	int T;
	int N,M;
	ll X1,X2,X3,X4;
	ll Y1,Y2,Y3,Y4;
	ll B,W;
	ll painted_white, painted_black;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		cin>>X1>>Y1>>X2>>Y2;
		cin>>X3>>Y3>>X4>>Y4;
		
		W = num_white(1,1,N,M);
		B = num_black(1,1,N,M);

		B += num_white(X3,Y3,X4,Y4);
		W -= num_white(X3,Y3,X4,Y4);

		W += num_black(X1,Y1,minm(X3-1, X2),Y2);
		B -= num_black(X1,Y1,minm(X3-1, X2),Y2);

		/*W += num_black(maxm(X4+1, X1),Y1,X2,Y2);
		B -= num_black(maxm(X4+1, X1),Y1,X2,Y2);

		W += num_black(maxm(X3, X1),max(Y4+1,Y1),minm(X4, X2),Y2);
		B -= num_black(maxm(X3, X1),max(Y4+1,Y1),minm(X4, X2),Y2);*/

		/*W += num_black(maxm(X4+1, X1),Y1,X2,Y2);
		B -= num_black(maxm(X4+1, X1),Y1,X2,Y2);*/
		
		cout<<W<<" "<<B<<endl;
	}
	return 0;
}