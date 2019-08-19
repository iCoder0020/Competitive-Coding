/*
ID: ishan-sang
PROG: Letter Phone
LANG: C++                  
*/

void f(vector<string> &ans, string A, map<int, vector<char>> &MAP, string &curr, int i, int N)
{
    if(i == N)
    {
        ans.push_back(curr);
        return;
    }
    for(auto it: MAP[A[i]-'0'])
    {
        curr += it;
        f(ans, A, MAP, curr, i+1, N);
        curr.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) 
{
    vector<string> ans;
    map<int, vector<char>> MAP;
    string curr = "";
    MAP[0] = {'0'};
    MAP[1] = {'1'};
    MAP[2] = {'a', 'b', 'c'};
    MAP[3] = {'d', 'e', 'f'};
    MAP[4] = {'g', 'h', 'i'};
    MAP[5] = {'j', 'k', 'l'};
    MAP[6] = {'m', 'n', 'o'};
    MAP[7] = {'p', 'q', 'r', 's'};
    MAP[8] = {'t', 'u', 'v'};
    MAP[9] = {'w', 'x', 'y', 'z'};
    f(ans, A, MAP, curr, 0, A.size());
    sort(ans.begin(), ans.end());
    return ans;
}
