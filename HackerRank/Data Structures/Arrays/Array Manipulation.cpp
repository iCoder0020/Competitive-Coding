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
    lli N,M;
    cin>>N>>M;
    lli arr[N] = {0};
    lli A,B,K;
    for(lli m = 0; m<M; m++)
    {
    	cin>>A>>B>>K;
    	arr[A-1] += K;
    	if(B < N)
    	{
    		arr[B] -= K;
    	}
    }
    lli max = 0;
    for(int n = 0; n<N; n++)
    {
    	if(arr[n] > 0)
    	{
    		lli sum = 0;
    		while(arr[n] >= 0 && n<N)
    		{
    			sum += arr[n];
    			n++;
    		}
    		if(sum > max)
    		{
    			max = sum;
    		}
    	}
    }
    cout<<max<<"\n";
    return 0;
}
