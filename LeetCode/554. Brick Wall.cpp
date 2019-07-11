/*
ID: iCoder0020
PROG: Brick Wall
LANG: C++                  
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        int N = wall.size();
        unordered_map<int,int>M;
        int maxm = 0;
        int d = 0;
        for(auto it: wall[0])
            d += it;
        for(int n = 0; n<N; n++)
        {
            int s = 0;
            for(auto it: wall[n])
            {
                s += it;
                M[s]++;
                if(M[s] > maxm && s!= d)
                    maxm = M[s];
            }
        }
        return N-maxm;
    }
};