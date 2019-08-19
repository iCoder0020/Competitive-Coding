/*
ID: ishan-sang
PROG: Longest Consecutive Sequence
LANG: C++                  
*/

int Solution::longestConsecutive(const vector<int> &A) 
{
    int N = A.size();
    map<int,int> M;
    for(auto it: A)
        M[it] = 1;
    int prev = INT_MIN, curr;
    int cnt = 1, max_cnt = 1;
    for(map<int,int> ::iterator it = M.begin(); it!=M.end(); it++)
    {
        curr = (*it).first;
        if(curr-prev == 1)
            cnt++;
        else
            cnt = 1;
        max_cnt = max(cnt, max_cnt);
        prev = curr;
    }
    return max_cnt;
}
