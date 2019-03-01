/*
ID: icoder_0020
PROG: Golden rectangles
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int N;
	cin>>N;
	pair<int, int> dim[N];
	int cnt = 0;
	double ratio1, ratio2;
	for(int n = 0; n<N; n++)
	{
		cin>>dim[n].first>>dim[n].second;
		ratio1 = (double)((double)(dim[n].first)/(double)(dim[n].second));
		ratio2 = (double)((double)(dim[n].second)/(double)(dim[n].first));
		if((ratio1>=1.6 && ratio1<=1.7) || (ratio2>=1.6 && ratio2<=1.7))
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
