/*
ID: iCoder0020
PROG: Array Manipulation
LANG: C++                  
*/

#include <bits/stdc++.h> 

using namespace std; 

typedef long long int lli;

int main()
{
    int N,M;
    cin>>N>>M;
    int *arr = new int [N]();
    int A,B,K;
    for(int m = 0; m<M; m++)
    {
    	cin>>A>>B>>K;  
    	arr[A-1] += K;
    	if(B < N)
    	{
    		arr[B] -= K;
    	}
    }
    lli max = 0;
    lli sum = 0;
    for(int n = 0; n<N; n++)
    {
    	sum += arr[n];
        if(sum>max)
        {
            max = sum;
        }
    }
    cout<<max<<"\n";
    return 0;
}
