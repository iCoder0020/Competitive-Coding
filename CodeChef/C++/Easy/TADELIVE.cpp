/*
ID: ishan_sang
PROG: TADELIVE
LANG: C++                  
*/
 
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,X,Y;
    cin>>N>>X>>Y;
    int A[N];
    int B[N];
    int C[N];
    int D[N];
    for(int n = 0; n<N; n++)
    {
        cin>>A[n];
    }
    for(int n = 0; n<N; n++)
    {
        cin>>B[n];
        C[n] = A[n] - B[n];
        D[n] = -1*C[n];
    }
    sort(C, C+N);
    sort(D, D+N);
    while(1)
    {
        if(X == 0)
        {
            while(Y!=0)
            {
                
            }
        }
    }
	return 0;
} 