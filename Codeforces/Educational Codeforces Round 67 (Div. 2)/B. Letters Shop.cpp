/*
ID: iCoder0020
PROG: Letters Shop
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int M;
	cin>>M;
	string names[M];
	for(int i = 0; i<M; i++)
		cin>>names[i];
	int idx[26][200001];
	int cnt[26] = {0};
	for(int n = 0; n<N; n++)
	{
		int c = S[n]-'a';
		cnt[c]++;
		idx[c][cnt[c]] = n+1;
	}
	for(int i = 0; i<M; i++)
	{
		int count[26] = {0};
		for(int j = 0; j<names[i].size(); j++)
			count[names[i][j] - 'a']++;
		int maxm = 0;
		for(int j = 0; j<26; j++)
			maxm = max(maxm, idx[j][count[j]]);
		cout<<maxm<<endl;
	}
	return 0;
}