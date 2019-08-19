/*
ID: ishan-sang
PROG: 2 Sum
LANG: C++                  
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    int N = A.size();
    vector<int> ans;
    map<int,int> MAP;
    for(int n = N-1; n>=0; n--)
        MAP[A[n]] = n+1;
    for(int n = 1; n<N; n++)
    {
        int t = B-A[n];
        if(MAP.find(t) != MAP.end())
            if(MAP[t] < n+1)
            {
                ans.insert(ans.begin(), {MAP[t], n+1});
                break;
            }
    }
    return ans;
}
