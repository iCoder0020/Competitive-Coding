/*
ID: ishan-sang
PROG: Window String
LANG: C++                  
*/

bool check(vector<int>&base, vector<int>&curr)
{
    for(int n = 0; n<128; n++)
    {
        if(base[n] == 0)
            continue;
        if(base[n]>curr[n])
            return false;
    }
    return true;
}
string Solution::minWindow(string A, string B) 
{
    string ans = "";
    vector<int> base(128, 0);
    vector<int> curr(128, 0);
    int N = A.size();
    int start = 0, end = -1, i = 0, j = N;
    for(auto it: B)
        base[(int)it]++;
    bool flag;
    for(int n = 0; n<N; n++)
    {
        curr[(int)A[n]]++;
        while(check(base, curr))
        {
            end = n;
            if(end-start<j-i)
                i = start, j = end;
            curr[(int)A[start]]--;
            start++;
        }
    }
    if(end != -1)
    {
        for(int n = i; n<=j; n++)
            ans += A[n];
    }
    return ans;
}
