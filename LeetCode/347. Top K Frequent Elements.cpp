/*
ID: iCoder0020
PROG: Top K Frequent Elements
LANG: C++                  
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> M;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto it: nums)
            M[it]++;
        for(auto it: M)
        {
            if(pq.size() < k)
                pq.push({it.second, it.first});
            else
            {
                if(it.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<int>v;
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            v.push_back(u);
        }
        return v;
    }
};