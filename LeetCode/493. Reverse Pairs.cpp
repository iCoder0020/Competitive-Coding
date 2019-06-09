/*
ID: iCoder0020
PROG: Reverse Pairs
LANG: C++                  
*/

class Solution {
public:
    int cntl;
    void merge_sort_combine(vector<long long int> &arr, int l, int m, int r)
	{
		int a = m-l;
		int b = r-m;
		int c = r-l;
		long long int A[a], B[b], C[c];
		int i = 0, j = 0, k = 0;
		for(int n = l; n<r; n++)
		{
			if(n<m)
				A[i++] = arr[n];
			else
				B[j++] = arr[n];
		}
		i = 0, j = 0;
	    int idx = 0;
	    int cnt = 0;
	    for(int n = l; n<m; n++)
	    {
	        while(idx<b && 2*B[idx] < A[n-l])
	        {
	            cnt++;
	            idx++;
	        }
	        cntl+=cnt;
	    }
		while(i<a && j<b)
		{
			if(A[i] < B[j])
				C[k++] = A[i++];
			else
				C[k++] = B[j++];
		}
		while(i<a)
			C[k++] = A[i++];
		while(j<b)	
			C[k++] = B[j++];
			
		for(int n = l; n<r; n++)
			arr[n] = C[n-l];
	}

	void merge_sort(vector<long long int> &A, int l, int r)
	{
		if(r-l<=1)
			return;
		else
		{
			int m = (r+l)/2 + (r-l)%2;
			merge_sort(A, l, m);
			merge_sort(A, m, r);
			merge_sort_combine(A, l, m, r);
		}
	}
    
    int reversePairs(vector<int>& nums) {
        int N = nums.size();
        cntl = 0;
        vector<long long int> nums1;
        for(auto it: nums)
            nums1.push_back((long long int)(it));
        merge_sort(nums1, 0, N);
        return cntl;
    }
};