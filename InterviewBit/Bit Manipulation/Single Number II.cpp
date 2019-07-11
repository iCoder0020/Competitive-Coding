/*
ID: ishan-sang
PROG: Single Number II
LANG: C++                  
*/

int Solution::singleNumber(const vector<int> &A) 
{
    int cnt[32] = {0};
    vector<int> idx;
    for(int i = 0; i<32; i++)
    {
        int f = (1<<i);
        for(auto it: A)
        {
            if(it & f)
                cnt[i]++;
        }
    }
    for(int i = 0; i<32; i++)
    {
        if(cnt[i]%3!=0)
            idx.push_back(i);
    }
    int ans = 0;
    for(auto it: idx)
        ans += (1<<it);
    return ans;
}
