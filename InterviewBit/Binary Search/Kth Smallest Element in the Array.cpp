/*
ID: ishan-sang
PROG: Kth Smallest Element in the Array
LANG: C++                  
*/

bool check(const vector<int> &A, int num, int B)
{
    int cnt = 0;
    for(auto it: A)
    {
        if(num>=it)
            cnt++;
    }
    // cout<<num<<" "<<cnt<<endl;
    return (cnt>=B);
}
int Solution::kthsmallest(const vector<int> &A, int B) 
{
    int lo = INT_MAX;
    int hi = INT_MIN;
    int mid;
    for(auto it: A)
        lo = min(lo, it), hi = max(hi, it);
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(check(A, mid, B))
            hi = mid;
        else 
            lo = mid+1;
    }
    return lo;
}
