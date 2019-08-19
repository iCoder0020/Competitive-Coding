/*
ID: ishan-sang
PROG: Word Ladder I
LANG: C++                  
*/

int bfs(string start, string end, set<string> &S)
{
    int cnt = 0;
    queue<pair<string,int>>Q;
    map<string,int>MAP;
    Q.push({start, 0});
    while(!Q.empty())
    {
        pair<string,int> p = Q.front();
        string str = p.first;
        int d = p.second+1;
        MAP[str] = 1;
        
        Q.pop();
        
        if(str == end)
        {
            cnt = d;
            break;
        }
        for(int i = 0; i<str.length(); i++)
        {
            for(char c = 'a'; c<='z'; c++)
            {
                if(c == str[i])
                    continue;
                string T = str;
                T[i] = c;
                if(MAP.find(T) == MAP.end() && S.find(T) != S.end())
                {
                    Q.push({T, d});
                }
            }
        }
    }
    return cnt;
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) 
{
    set<string>S;
    for(auto it: dictV)
        S.insert(it);
    S.insert(end);
    int cnt = bfs(start, end, S);
    return cnt;
}
