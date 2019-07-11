/*
ID: iCoder0020
PROG: Asteroid Collision
LANG: C++                  
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>S;
        bool add = true;
        for(auto it: asteroids)
        {
            if(S.empty())
                S.push(it);
            else
            {
                while(!S.empty() && it<0 && S.top()>0)
                {
                    if(abs(it) < S.top())
                    {
                        add = false;
                        break;
                    }
                    else if(abs(it) > S.top())
                    {
                        S.pop();
                    }
                    else
                    {
                        S.pop();
                        add = false;
                        break;
                    }
                }
                if(add)
                    S.push(it);
                add = true;
            }
        }
        vector<int>v;
        while(!S.empty())
        {
            v.push_back(S.top());
            S.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};