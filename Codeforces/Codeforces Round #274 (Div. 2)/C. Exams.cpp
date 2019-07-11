/*
ID: iCoder0020
PROG: Exams
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	pair<int,int> exams[N];
	for(int n = 0; n<N; n++)
		cin>>exams[n].first>>exams[n].second;
	sort(exams, exams+N);
	int day = 0;
	for(int n = 0; n<N; n++)
	{
		int minm = min(exams[n].first, exams[n].second);
		int maxm = max(exams[n].first, exams[n].second);
		if(day <= minm)
			day = minm;
		else
			day = maxm;
	}
	cout<<day<<endl;
	return 0;
}