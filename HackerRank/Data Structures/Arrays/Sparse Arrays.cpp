/*
ID: iCoder0020
PROG: Sparse Arrays
LANG: C++                  
*/

#include <bits/stdc++.h> 

using namespace std; 

int main()
{
    int N,Q;
    cin>>N;
    string input[N];
    for(int n = 0; n<N; n++)
    {
        cin>>input[n];
    }
    cin>>Q;
    string queries[Q];
     int answer[Q] = {0};
    for(int q = 0; q<Q; q++)
    {
        cin>>queries[q];
        for(int n = 0; n<N; n++)
        {
            if(input[n] == queries[q])
            {
                answer[q]++;
            }
        }
    }
    for(int n = 0; n<Q; n++)
    {
        cout<<answer[n]<<"\n";
    }
    return 0;
}
