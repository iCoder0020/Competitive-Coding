#include <bits/stdc++.h>

using namespace std;

#define int long long

void print(set<int>&S1, set<int>&S2)
{
	for(auto it: S1)
		cout<<it<<" ";
	cout<<endl;
	for(auto it: S2)
		cout<<it<<" ";
	cout<<endl;
}

int32_t main()
{
	int N;
	cin>>N;
	map<int,int> freq;
	set<int>S;
	for(int n = 0; n<N; n++)
	{
		int x;
		cin>>x;
		S.insert(x);
		freq[x]++;
	}
	vector<int> Y;
	for(auto it: S)
		Y.push_back(it);

	set<int> min_set;
	set<int> max_set;

	for(int n = 0; n<Y.size(); n++)
	{
		if(n+1 == Y.size())
		{
			min_set.insert(Y[n]);
			break;
		}
		if(Y[n] == Y[n+1]-1)
		{
			min_set.insert(Y[n]+1);
			n++;
			if(n<N && Y[n+1] == Y[n]+1)
				n++;
		}
		else if(Y[n] == Y[n+1]-2)
		{
			min_set.insert(Y[n]+1);
			n++;
		}
		else
			min_set.insert(Y[n]);
	}

	for(auto it: S)
	{
		if(freq[it] >= 1)
			max_set.insert(it);
		if(freq[it] >= 3)
		{
			max_set.insert(it-1);
			max_set.insert(it+1);
		}
	}
	for(auto it: S)
	{
		if(freq[it] == 2)
		{
			if(max_set.find(it-1) == max_set.end())
				max_set.insert(it-1);
			else
				max_set.insert(it+1);
		}
	}

	// print(min_set, max_set);

	cout<<min_set.size()<<" "<<max_set.size()<<endl;
	return 0;
}
