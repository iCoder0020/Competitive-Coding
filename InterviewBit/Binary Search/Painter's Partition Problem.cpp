/*
ID: ishan-sang
PROG: Painter's Partition Problem
LANG: C++                  
*/

#define MOD 10000003

bool check(vector<int> &A, int K, int T)
{
    int k = 0;
    int s = 0;
    for(auto it: A)
    {
        if(s + it <= T)
            s = s+it;
        else
        {
            k++;
            s = it;
        }
    }
    k++;
    return (k<=K);
}

int Solution::paint(int A, int B, vector<int> &C) 
{
    long long int lo,mid,hi,ans;
    lo = *max_element(C.begin(), C.end());
    hi = INT_MAX;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(check(C, A, mid))
            hi = mid;
        else
            lo = mid+1;
    }
    ans = (lo*B)%MOD;
    return ans;
}
