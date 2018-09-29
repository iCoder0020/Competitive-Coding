/*
ID: iCoder0020
PROG: Cut the sticks
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> sticks;
	int num;
	for(int n = 0; n<N; n++)
	{
		cin>>num;
		sticks.push_back(num);
	}
	sort(sticks.begin(), sticks.end());
	while(sticks.size()!=0)
	{
		if(sticks.size()>1)
		{
			for(int i = 1; i<sticks.size(); i++)
			{
				sticks[i] = sticks[i]-sticks[0];
			}
		}
		sticks[0] = 0;
		cout<<sticks.size()<<"\n";
		while(sticks[0] == 0)
		{
			sticks.erase(sticks.begin());
			if(sticks.size() == 0)
			{
				break;
			}
		}
	}
	return 0;
}
