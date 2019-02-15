/*
ID: ishan_sang
PROG: FORESTGA
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int li;

const li MAX_TIME = 1e18;

li f(pair<li,li> tree[], li N, li mid, li L)
{
    li count = 0;
    for(int n = 0; n<N; n++)
    {
        if(tree[n].first + mid*tree[n].second >= L || tree[n].first + mid*tree[n].second < 0)
        {
            count += tree[n].first + mid*tree[n].second;
            if(count < 0 || tree[n].first + mid*tree[n].second < 0)
            {
                return count;
            }
        }
    }
    return count;
}

int main()
{
    li N,W,L;
    cin>>N>>W>>L;
    pair<li,li> tree[N];
    for(li n = 0; n<N; n++)
    {
        cin>>tree[n].first>>tree[n].second;
    }
    li min = 0;
    li max = MAX_TIME;
    li mid;
    while(1)
    {
        mid = (min+max)/2;
        li ans = f(tree,N,mid,L);
        //cout<<mid<<" "<<ans<<endl;
        if(min == max)
        {
            cout<<mid<<endl;
            break;
        }
        else if(ans >= W || ans < 0)
        {
            max = mid;
        }
        else 
        {
            min = mid+1;
        }
    }
    return 0;
} 