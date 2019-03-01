/*
ID: ishan_sang
PROG: PROBLEMS
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct data
{
	int SC;
	int NS;
};

struct difficulty
{
	int N;
	int problem_num;
};

bool CompareSC(const data& lhs, const data& rhs)
{
	return lhs.SC < rhs.SC;
}

bool CompareDiff(const difficulty& lhs, const difficulty& rhs)
{
	if(lhs.N == rhs.N)
	{
		return lhs.problem_num<rhs.problem_num;
	}
	return lhs.N < rhs.N;
}

int main()
{
	int P,S;
	cin>>P>>S;
	data D[P][S];
	int count;
	difficulty diff[P];
	int order[P];
	for(int i = 0; i<P; i++)
	{
		count = 0;
		for(int j = 0; j<S; j++)
		{
			cin>>D[i][j].SC;
		}
		for(int j = 0; j<S; j++)
		{
			cin>>D[i][j].NS;
		}

		sort(D[i], D[i]+S, CompareSC);

		for(int j = 0; j<S-1; j++)
		{
			if(D[i][j].NS>D[i][j+1].NS)
			{
				count++;
			}
		}

		diff[i].N = count;
		diff[i].problem_num = i+1;
	}
	sort(diff, diff+P, CompareDiff);
	for(int i = 0; i<P; i++)
	{
		cout<<diff[i].problem_num<<"\n";
	}
	return 0;
}