/*
ID: iCoder0020
PROG: Last Stone Weight
LANG: C++                  
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones)
            pq.push(it);
        while(pq.size() > 1)
        {
            int u = pq.top();
            pq.pop();
            int v = pq.top();
            pq.pop();
            if(u!=v)
                pq.push(u-v);
        }
        if(pq.empty())
            return 0;
        else
            return pq.top();
    }
};