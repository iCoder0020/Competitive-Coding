/*
ID: ishan_sang
PROG: ABCSTR
LANG: C++
*/
 
#include <bits/stdc++.h>

#define int long long

using namespace std;
 
int32_t main()
{
    string S;
    cin>>S;
    int len = S.length();
    int char_count[len][3];
    map<pair<int,int>,int>M;
    for(int n = 0; n<len; n++)
    {
        for(int m = 0; m<3; m++)
        {
            char_count[n][m] = 0;
        }
    }
    for(int n = 0; n<len; n++)
    {
        if(n != 0)
        {
            for(int m = 0; m<3; m++)
            {
                char_count[n][m] = char_count[n-1][m];
            } 
        }
        char_count[n][S[n]-'A']++;
    }
    M[{0,0}] = 1;
    for(int n = 0; n<len; n++)
    {
        int m1 = char_count[n][0] - char_count[n][1];
        int m2 = char_count[n][0] - char_count[n][2];
        if(M.find({m1, m2}) == M.end())
        {
            M[{m1, m2}] = 1;
        }
        else
        {
            M[{m1, m2}]++;
        }
    }
    int count = 0;
    for(pair<pair<int,int>,int> it: M)
    {        
        count += (it.second*(it.second-1))/2;
    }
    cout<<count<<endl;
    return 0;
}