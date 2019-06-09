/*
ID: iCoder0020
PROG: Sort Colors
LANG: C++                  
*/

class Solution {
public:
    void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
    
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
            return;
        int i[3] = {0, 0, n-1};
        while(i[0]<n && nums[i[0]] == 0)
            i[0]++;
        if(i[0] == n)
            return;
        while(i[2]>0 && nums[i[2]] == 2)
            i[2]--;
        if(i[2] <= i[0])
            return;
        for(i[1] = i[0]; i[1] <= i[2];)
        {
            if(nums[i[1]] == 1)
                i[1]++;
            else if(nums[i[1]] == 0)
            {
                swap(nums[i[0]], nums[i[1]]);
                i[0]++;
                i[1]++;
            }
            else
            {
                swap(nums[i[1]], nums[i[2]]);
                i[2]--;
            }
        }
    }
};