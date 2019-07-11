/*
ID: ishan_sang
PROG: KS2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

char get_num(string N)
{
    int sum = 0;
    for(auto it: N)
        sum = (sum + it - '0')%10;
    if(sum == 0)
        return '0';
    return (char)('0'+10-sum);
}

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string V;
        cin>>V;
        string S = V + get_num(V);
        cout<<S<<endl;
    }
    return 0;
}