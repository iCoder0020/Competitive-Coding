/*
ID: ishansa2
PROG: wormhole
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1LL<<32

ofstream fout("wormhole.out");
ifstream fin("wormhole.in");

int N;
int x,y;
int total;
vector<pair<int,int>>v;
map<int,vector<int>>M;
vector<int>pairing;
map<pair<int,int>,int>WH;

int check_and_add()
{
    // for(int i = 0; i<N; i++)
    //     cout<<i<<" "<<pairing[i]<<endl;
    vector<bool>checked(N,false);
    for(int i = 0; i<N; i++)
    {
        if(checked[i] == true)
            continue;
        set<pair<int,int>> S;
        int idx = i;
        while(1)
        {
            // cout<<"telep to: "<<idx<<endl;
            int x = v[idx].first;
            int y = v[idx].second;
            if(S.find({x,y}) != S.end())
            {
                // cout<<"LOOP!"<<endl;
                return 1;
            }
            checked[idx] = true;
            S.insert({x,y});
            int right_x;
           
            for(int j = 0; j<M[y].size(); j++)
            {
                if(M[y][j] == x)
                {
                    if(j+1 == M[y].size())
                        right_x = INF;
                    else
                        right_x = M[y][j+1];
                    break;
                }
            }
            if(right_x == INF)
            {
                // cout<<"reached inf: no loop from here"<<endl;
                break;
            }
            idx = WH[{right_x, y}];
            // cout<<"moved to: "<<idx<<endl;
            idx = pairing[idx];
            checked[idx] = true;
        }
    }
    // cout<<endl;
    // cout<<"no loops found"<<endl<<endl;
    return 0;
}

void solve()
{
    int i;
    for(i = 0; i<N; i++)
        if(pairing[i] == -1)
            break;
    if(i == N)
    {
        total += check_and_add();
        return;
    }
    for(int j = i+1; j<N; j++)
    {
        if(pairing[j] != -1)
            continue;
        pairing[i] = j;
        pairing[j] = i;
        solve();
        pairing[i] = pairing[j] = -1;
    }
}

bool mysort(pair<int,int>&P, pair<int,int>&Q)
{
    if(P.first < Q.first)
        return true;
    return false;
}

int32_t main()
{
    fin>>N;
    v.resize(N);
    pairing.resize(N,-1);
    for(int n = 0; n<N; n++)
    {
        fin>>v[n].first>>v[n].second;
        WH[{v[n].first, v[n].second}] = n;
        M[v[n].second].push_back(v[n].first);
    }
    for(auto &it: M)
        sort(it.second.begin(), it.second.end());
    total = 0;
    solve();
    fout<<total<<endl;
    return 0;
}