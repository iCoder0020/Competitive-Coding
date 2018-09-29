/*
ID: iCoder0020
PROG: Equality
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,K;
	string S;
	cin>>N>>K;
	cin>>S;
	int min;
	int occurences[K] = {0};
	for(int n = 0; n<N; n++)
	{
		occurences[(int)(S[n])-65]++;
	}
	min = occurences[0];
	for(int k = 0; k<K; k++)
	{
		min = (min<occurences[k])?min:occurences[k];
	}
	cout<<min*K<<"\n";
	return 0;
}