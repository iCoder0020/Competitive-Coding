/*
ID: iCoder0020
PROG: K Closest Points to Origin
LANG: C++                  
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        vector<pair<int,int>> V;
        vector<vector<int>> ans;
        for(int n = 0; n<points.size(); n++)
            V.push_back({points[n][0]*points[n][0] + points[n][1]*points[n][1], n});
        sort(V.begin(), V.end());
        for(int k = 0; k<K; k++)
            ans.push_back(points[V[k].second]);
        return ans;
    }
};