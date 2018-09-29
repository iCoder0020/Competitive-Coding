/*
ID: ishan_sang
PROG: CHEFRUN
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int X1,X2,X3,V1,V2;
	int D1,D2;
	float T1,T2;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>X1>>X2>>X3>>V1>>V2;
		D1 = (X1-X3>0)?(X1-X3):(X3-X1);
		D2 = (X2-X3>0)?(X2-X3):(X3-X2);
		T1= (float)(D1)/V1;
		T2 = (float)(D2)/V2;
		if(T1 == T2)
		{
			cout<<"Draw";
		}
		else if(T1 < T2)
		{
			cout<<"Chef";
		}
		else
		{
			cout<<"Kefa";
		}
		cout<<"\n";
	}
	return 0;
}