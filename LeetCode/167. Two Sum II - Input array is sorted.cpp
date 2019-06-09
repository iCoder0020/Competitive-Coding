/*
ID: iCoder0020
PROG: Two Sum II - Input array is sorted
LANG: C++                  
*/

class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int N = numbers.size();
        int i = 0;
        int j = N-1;
        vector<int>ans = {-1,-1};
        while(i<j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }
            else if(numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
            
        }
        return ans;
    }
};