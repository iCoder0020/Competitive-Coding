/*
ID: iCoder0020
PROG: Sasha and a Bit of Relax
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long int

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	map <int,int> MAP[2];
    MAP[1][0]++;
    int count = 0;
    int x = 0;
    for(int n = 0; n<N; n++)
    {
        x = x^A[n];
        if(MAP[n&1].find(x) != MAP[n&1].end())
        {
        	count += MAP[n&1][x];
        }
        MAP[n&1][x]++;
    }
    cout<<count<<endl;
	return 0;
}