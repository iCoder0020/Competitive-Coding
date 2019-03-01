/*
ID: iCoder0020
PROG: Stages
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,K;
	int letter[26] = {0};
	string S;
	cin>>N>>K;
	cin>>S;
	for(int s = 0; s<S.length(); s++)
	{
		letter[(int)(S[s] - 'a')] = 1;
	}
	int index = 0;
	int answer = 0;
	while(K)
	{
		while(index<26 && letter[index] == 0)
		{
			index++;
		}
		if(index >= 26)
 		{
 			answer = -1;
 			break;
 		}
 		answer += (index+1);
 		index += 2;
		K--;
	}
	cout<<answer<<"\n";
	return 0;
}