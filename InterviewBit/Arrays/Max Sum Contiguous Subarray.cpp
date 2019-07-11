/*
ID: ishan-sang
PROG: Max Sum Contiguous Subarray
LANG: C++                  
*/

int Solution::maxSubArray(const vector<int> &A) 
{
    long long int sum = 0;
    long long int max_sum = LONG_MIN;
    for(auto it: A)
    {
        sum = max(it+sum, (long long)it);
        max_sum = max(sum, max_sum);
    }
    return max(sum, max_sum);
}

