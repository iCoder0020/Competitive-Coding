/*
ID: ishan_sang
PROG: COMPEXP
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    long double avg_length;
  	cout<<fixed<<setprecision(10);
    for(int t = 0; t<T; t++)
    {
        long double N,K;
        cin>>N>>K;
        avg_length = 2.0*(N-((N-1)/K));
        cout<<avg_length<<"\n";
    }
    return 0;
}