/*
ID: icoder_0020
PROG: Digit Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long X,Y;
    int K, num_dig = 0;
    cin>>X>>K;
    Y = X;
    while(Y)
    {
        Y/=10;
        num_dig++;
    }
    int number[num_dig];
    for(int i = 0; i<num_dig; i++)
    {
        number[i] = X%10;
        X/=10;
    }
    for(int i = num_dig-1; i>=0; i--)
    {
        if(K>0 && number[i]!=9)
        {
            number[i] = 9;
            K--;
        }
        cout<<number[i];
    }
    cout<<"\n";
    return 0;
}