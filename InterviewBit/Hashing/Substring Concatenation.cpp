/*
ID: ishan-sang
PROG: Substring Concatenation
LANG: C++                  
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) 
{
    int N = B.size();
    int M = B[0].size();
    map<string,int> MAP;
    map<string,int> curr_cnt;
    for(auto it: B)
        MAP[it]++;
    vector<int> ans;
    int cnt;
    for(int n = 0; n<A.length(); n++)
    {
        cnt = 0;
        int start = n;
        curr_cnt.clear();
        while(1)
        {
            string temp = A.substr(n, M);
            if(MAP.find(temp) == MAP.end())
                break;
            curr_cnt[temp]++;
            if(curr_cnt[temp] > MAP[temp])
                break;
            cnt++;
            if(cnt == N)
            {
                ans.push_back(n-M*(N-1));
                break;
            }
            n+=M;
            if(n>=A.length())
                break;
        }
        n = start;
    }
    return ans;
}
