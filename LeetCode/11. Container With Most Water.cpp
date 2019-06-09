/*
ID: iCoder0020
PROG: Container With Most Water
LANG: C++                  
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int i = 0, j = N-1;
        int maxm = 0;
        while(i<j)
        {
            int h = min(height[i], height[j]);
            if((j-i)*h > maxm)
                maxm = (j-i)*h;
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxm;
    }
};