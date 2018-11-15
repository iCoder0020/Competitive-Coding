/*
ID: ishan_sang
PROG: FRJUMP
LANG: C++
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define mod  1000000007
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    long long F[N];
    for(int i = 0; i<N; i++)
    {
        cin>>F[i];
    }
    int Q;
    cin>>Q;
    int choice;
    int p,f;
    int R;
    long long enjoyment;
    long long temp;
    int first_digit;
    for(int i = 0; i<Q; i++)
    {
        enjoyment = 1;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>p;
                cin>>f;
                F[p-1] = f;
                break;
 
            case 2:
                cin>>R;
                for(int j = 0; j<N; j+=R)
                {
                    enjoyment = ((enjoyment%mod)*(F[j]%mod))%mod;
                }
                temp = enjoyment;
                while(temp)
                {
                    first_digit = temp%10;
                    temp/=10;
                }
                cout<<first_digit<<" "<<enjoyment<<"\n";
                break;
 
            default:
                break;
        }
    }
    return 0;
}