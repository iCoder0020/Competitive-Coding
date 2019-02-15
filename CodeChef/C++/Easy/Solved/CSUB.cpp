/*
ID: ishan_sang
PROG: CSUB
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        int N;
        cin>>N;
        string S;
        cin>>S;
        long long int count = 0;
        for(int n = 0; n<N; n++)
        {
            if(S[n] == '1')
            {
                count++;
            }
        }
        long long int ans = ((count+1)*(count))/2;
        cout<<ans<<endl;
    }
    return 0;
}