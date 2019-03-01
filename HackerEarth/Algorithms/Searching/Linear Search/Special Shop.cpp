/*
ID: icoder_0020
PROG: Special Shop
LANG: C++                  
*/

#include <bits/stdc++.h>
 
typedef long long int li;

li min(li a, li b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

using namespace std;

int main()
{
	li T,N,A,B;
	li cost;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>A>>B;
		li X1 = (B*N)/(A+B);
		li X2 = X1+1;
		li Y1 = N-X1;
		li Y2 = N-X2;
		cost = min(A*X1*X1+B*Y1*Y1, A*X2*X2+B*Y2*Y2);
		cout<<cost<<endl;
	}
	return 0;
}
