/*
ID: iCoder0020
PROG: NN and the Optical Illusion
LANG: C++                  
*/

#include <bits/stdc++.h>

#define PI 3.14159265358979323

using namespace std;

typedef long double ld;

int main()
{
	ld N,R;
	cin>>N>>R;
	ld r = R/((1/sin(PI/N)) - 1);
	cout<<fixed<<setprecision(10)<<r<<endl;
	return 0;
}