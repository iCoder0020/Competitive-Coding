/*
ID: ishan-sang
PROG: Anagrams
LANG: C++                  
*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    int N = A.size();
    vector<vector<int>> ans;
    map<vector<int>, vector<int>> MAP;
    for(int n = 0; n<N; n++)
    {
        vector<int> temp (26, 0);
        for(auto it: A[n])
            temp[it-'a']++;
        MAP[temp].push_back(n+1);
    }
    for(auto it: MAP)
        ans.push_back(it.second);
    return ans;
}
