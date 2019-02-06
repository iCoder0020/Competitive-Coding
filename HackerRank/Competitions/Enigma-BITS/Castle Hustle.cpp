/*
ID: iCoder0020
PROG: Castle Hustle
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,C,K;
        cin>>N>>C>>K;
        int A[K];
        bool possible = true;
        for(int n = 0; n<K; n++)
        {
            cin>>A[n];
            if(n == 0)
            {
                if(A[0] > C)
                {
                    possible = false;
                }
            }
            else
            {
                if(A[n]-A[n-1]>C)
                {
                    possible = false;
                }
            }
        }
        if(N-A[K-1] >C)
        {
            possible = false;
        }
        if(possible)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}