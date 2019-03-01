/*
ID: ishan_sang
PROG: DIFNEIGH
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 4

void remove(vector<vector<set<int>>> &choices, int i, int j, int N, int M, int temp)
{
	if(i>=0 && j>=0 && i<N && j<M)
	{
		auto it = choices[i][j].find(temp);
		if(it != choices[i][j].end())
		{
			choices[i][j].erase(it);
		}
	}
}

int main()
{
	int T;
	cin>>T;
	int N,M;
	
	vector <vector<int>> mat50x50(50, vector<int> (50));

	set <int> default_set50x50;

	for(int i = 1; i<=MAX; i++)
	{
		default_set50x50.insert(i);
	}

	vector <vector<set<int>>> choices50x50(50, vector<set<int>> (50));

	for(int i = 0; i<50; i++)
	{
		for(int j = 0; j<50; j++)
		{
			choices50x50[i][j] = default_set50x50;
		}
	}

	for(int i = 0; i<50; i++)
	{
		for(int j = 0; j<50; j++)
		{
			int temp = 0;
			for(int k = 1; k<=MAX; k++)
			{
				auto it = choices50x50[i][j].find(k);
				if(it!=choices50x50[i][j].end())
				{
					temp = k;
					break;
				}
			}
			mat50x50[i][j] = temp;

			remove(choices50x50, i, j+2, 50, 50, temp);
			remove(choices50x50, i+1, j+1, 50, 50, temp);
			remove(choices50x50, i+2, j, 50, 50, temp);
			remove(choices50x50, i+1, j-1, 50, 50, temp);
			remove(choices50x50, i, j-2, 50, 50, temp);
			remove(choices50x50, i-1, j-1, 50, 50, temp);
			remove(choices50x50, i-2, j, 50, 50, temp);
			remove(choices50x50, i-1, j+1, 50, 50, temp);
		}
	}

	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		int K = 0;

		vector <vector<int>> A(N, vector<int> (M));

		if((N == 1 && M == 1) || (N == 1 && M == 2) || (N == 2 && M == 1))
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					A[i][j] = 1;
				}
			}
			K = 1;
		}
		else if(N == 2)
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					A[i][j] = (j%3)+1;
				}
			}
			K = min(M,3);
		}
		else if(M == 2)
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					A[i][j] = (i%3)+1;
				}
			}
			K = min(N,3);
		}
		else
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					A[i][j] = mat50x50[i][j];
				}
			}
			if(N == 1 || M == 1)
			{
				K = 2;
			}
			else
			{
				K = 4;
			}
		}
		
		cout<<K<<endl;
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}