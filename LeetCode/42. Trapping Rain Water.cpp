/*
ID: iCoder0020
PROG: Trapping Rain Water
LANG: C++                  
*/

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int l = 0;
        int r = height.size()-1;
        int l_max = 0, r_max = 0;
        int ans = 0;
        while(l < r)
        {
            if(height[l] < height[r])
            {   
                if(height[l] >= l_max)
                    l_max = height[l];
                else
                    ans += l_max-height[l];
                l++;
            }
            else
            {
                if(height[r] >= r_max)
                    r_max = height[r];
                else
                    ans += r_max-height[r];
                r--;
            }
        }
        return ans;
    }
};