/*
ID: ishan_sang
PROG: PETERSEN
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
        string S;
        cin>>S;

        map<string, pair<char,char>>M;

        M["AB"] = {'0', '1'};
        M["AC"] = {'5', '7'};
        M["AD"] = {'5', '8'};
        M["AE"] = {'0', '4'};

        M["BA"] = {'1', '0'};
        M["BC"] = {'1', '2'};
        M["BD"] = {'6', '8'};
        M["BE"] = {'6', '9'};

        M["CA"] = {'7', '5'};
        M["CB"] = {'2', '1'};
        M["CD"] = {'2', '3'};
        M["CE"] = {'7', '9'};

        M["DA"] = {'8', '5'};
        M["DB"] = {'8', '6'};
        M["DC"] = {'3', '2'};
        M["DE"] = {'3', '4'};

        M["EA"] = {'4', '0'};
        M["EB"] = {'9', '6'};
        M["EC"] = {'9', '7'};
        M["ED"] = {'4', '3'};

        int N = S.length();

        bool possible = true;
        bool p_pr = false;

        string ans(N, 'e');

        for(int n = 0; n<N-1; n++)
        {
            if(S[n] != S[n+1])
            {
                p_pr = true;
                string str = "";
                str += S[n];
                str += S[n+1];
                pair<char,char> p = M[str];
                if((p.first!=ans[n] && ans[n] != 'e') || (n>0 && ans[n-1] == p.first) || (n<N-1 && ans[n+1] == p.first))
                {
                    possible = false;
                    break;
                }
                else
                    ans[n] = p.first;
                if((p.second!=ans[n+1] && ans[n+1] != 'e') || (n+1>0 && ans[n] == p.second) || (n<N-2 && ans[n+2] == p.second))
                {
                    possible = false;
                    break;
                }
                else 
                    ans[n+1] = p.second;
            }
        }
        if(!p_pr)
            for(int n = 0; n<N; n++)
                ans[n] = (n%2)?S[n]-'A'+'5':S[n]-'A'+'0';
        if(possible)
        {
            if(ans[0] == 'e')
            {
                int i = 1;
                while(ans[i] == 'e')
                    i++;
                i--;
                for(i; i>=0; i--)
                    ans[i] = (ans[i+1]-'0'>=5)?ans[i+1]-5:ans[i+1]+5;
            }
            for(int n = 1; n<N; n++)
            {
                if(ans[n] == 'e')
                    ans[n] = (ans[n-1]-'0'>=5)?ans[n-1]-5:ans[n-1]+5;
            }
            cout<<ans;
        }
        else
            cout<<-1;
        cout<<endl;
    }   
    return 0;
}