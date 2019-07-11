/*
ID: iCoder0020
PROG: Range Sum Query - Immutable
LANG: C++                  
*/

class NumArray {
public:
    vector<int>arr;
    vector<int>pre;
    NumArray(vector<int>& nums) {
        arr = nums;
        if(arr.size() != 0)
        {
            pre.resize(arr.size(), 0);
            pre[0] = arr[0];
            for(int i = 1; i<arr.size();i++)
                pre[i] = pre[i-1]+arr[i];
        }
        else
            pre.push_back(0);
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return pre[j];
        else
            return pre[j]-pre[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */