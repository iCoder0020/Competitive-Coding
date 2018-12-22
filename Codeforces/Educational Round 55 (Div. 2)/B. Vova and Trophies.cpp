/*
ID: iCoder0020
PROG: Vova and Trophies
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	char trophies[N];
	int count_G = 0;
	int count_S = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>trophies[n];
		if(trophies[n] == 'G')
		{
			count_G++;
		}
		else
		{
			count_S++;
		}
	}
	if(count_G == 0)
	{
		cout<<0<<endl;
	}
	else if(count_S == 0)
	{
		cout<<N<<endl;
	}
	else
	{
		vector <int> S_indices;
		S_indices.push_back(-1);
		for(int n = 0; n<N; n++)
		{
			if(trophies[n] == 'S')
			{
				S_indices.push_back(n);
			}
		}
		S_indices.push_back(N);

		vector <int> no_S;
		for(int n = 0; n<S_indices.size()-1; n++)
		{
			no_S.push_back(S_indices[n+1] - S_indices[n] - 1);
		}
		int max_no_S = *max_element(no_S.begin(), no_S.end());

		vector <int> one_S;
		for(int n = 0; n<S_indices.size()-2; n++)
		{
			one_S.push_back(S_indices[n+2] - S_indices[n] - 1);
		}
		int max_one_S = -1;

		for(int n = 0; n<one_S.size(); n++)
		{
			if(one_S[n] <= count_G && one_S[n] > max_one_S)
			{
				max_one_S = one_S[n];
			}
			else if(one_S[n]-1 <= count_G && one_S[n]-1 > max_one_S)
			{
				max_one_S = one_S[n]-1;
			}
		}

		if(max_one_S > max_no_S)
		{
			cout<<max_one_S<<endl;
		}
		else
		{
			cout<<max_no_S<<endl;
		}
	}
	return 0;
}