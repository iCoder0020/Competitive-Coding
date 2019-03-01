/*
ID: ishan_sang
PROG: CHEFBM
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,P;
    cin>>N>>M>>P;
    int x,y;
    int ans[N+1];
    for(int n = 1; n<=N; n++)
    {
        ans[n] = M-1;
    }
    map <pair<int,int>, int> MAP;
    for(int p = 0; p<P; p++)
    {
        cin>>x>>y;
        if(y == 1)
        {
            ans[x]--;
        }
        if(y == M)
        {
           ans[x]++; 
        }
        if(MAP.find({x,y}) == MAP.end())
        {
            MAP[{x,y}] = 1;
        }
        else
        {
            MAP[{x,y}]++;
        }
    }
    for(auto it: MAP)
    {
        int x = it.first.first;

        if(ans[x] >= 0) 
        {
            int curr_y = it.first.second;
            int curr_inc = it.second;

            int prev_y = curr_y-1;
            int prev_inc = 0;

            int next_y = curr_y+1;
            int next_inc = 0;

            if(prev_y >= 1)
            {
                auto it1 = MAP.find({x,prev_y});
                if(it1 == MAP.end())
                {
                    prev_inc = 0;
                }
                else
                {
                    prev_inc = (*it1).second;
                }
                if(prev_y + prev_inc > curr_y + curr_inc)
                {
                    ans[x] = -1;
                }
            }
            if(next_y <= M)
            {
                auto it1 = MAP.find({x,next_y});
                if(it1 == MAP.end())
                {
                    next_inc = 0;
                }
                else
                {
                    next_inc = (*it1).second;
                }
                if(next_y + next_inc < curr_y + curr_inc)
                {
                    ans[x] = -1;
                }
            }
        }
        else
        {
            ans[x] = -1;
        }
    }
    for(int n = 1; n<=N; n++)
    {
        cout<<ans[n]<<endl;
    }
    return 0;
} 