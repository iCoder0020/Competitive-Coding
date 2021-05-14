#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		string A,B;
		cin>>A>>B;
		bool p = true;
		map<char, vector<char>>MAP;
		for(int n = 0; n<N; n++)
		{
			if(A[n]>B[n])
				p = false;
			else
				MAP[A[n]].push_back(B[n]);
		}
		for(auto it: MAP)
				sort(it.begin(), it.end());
		map<char,char>M;
		for(char ch = 'a'; ch<='z'; ch++)
			M[ch] = ch;
		for(int n = 0; n<N; n++)
		{
			if(A[n]<B[n])
			{
				if(MAP[A[n]][0] == A[n] && MAP[A[n]].size()>1)
					p = false;
			}
		}
		if(!p)
			cout<<-1;
		else
		{

		}
		cout<<endl;
	}
	return 0;
}