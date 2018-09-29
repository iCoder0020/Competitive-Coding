/*
ID: ishan_sang
PROG: NAICHEF 
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N,A,B;
	int temp;
	double prob1, prob2, prob;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		cin>>N;
		int num_count[N]={0};
		cin>>A>>B;
		for(int n=0; n<N; n++)
		{
			cin>>temp;
			num_count[temp-1]++;
		}
		prob1 = ((double)(num_count[A-1])/(double)(N));
		prob2 = ((double)(num_count[B-1])/(double)(N));
		prob = prob1*prob2;
		cout<<prob<<"\n";
	}
	return 0;
}
