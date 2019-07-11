/*
ID: ishan-sang
PROG: Amazing Subarrays
LANG: C++                  
*/

#define MOD 10003
int Solution::solve(string A) 
{
    long long int ans = 0;
    vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i<A.size(); i++)
    {
        auto it = find(v.begin(), v.end(), A[i]);
        if(it != v.end())
            ans = (ans + (A.size()-i))%MOD;
    }
    return ans;
}
