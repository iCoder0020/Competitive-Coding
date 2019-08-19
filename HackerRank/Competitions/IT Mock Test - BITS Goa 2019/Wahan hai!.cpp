/*
ID: iCoder0020
PROG: Wahan hai!
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        string W,N;
        cin>>W>>N;
        int w = W.length();
        int n = N.length();
        if(w>n)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            int count[26] = {0};
            for(auto it: W)
                count[it-'A']++;
            int count_big[26] = {0};
            int start = 0;
            int cnt = 0;
            bool flag;
            for(int i = 0; i<n; i++)
            {
                count_big[N[i]-'A']++;
                if(i>=w-1)
                {
                    flag = true;
                    for(int j = 0; j<26; j++)
                    {
                        if(count[j] != count_big[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        cnt++;
                    count_big[N[start]-'A']--;
                    start++;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
