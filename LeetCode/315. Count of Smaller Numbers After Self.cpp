/*
ID: iCoder0020
PROG: Count of Smaller Numbers After Self
LANG: C++                  
*/

class Solution {
public:
    vector<int> counts;
    vector<pair<int,int>> elements;
    void merge_sort_combine(vector<pair<int,int>> &arr, int l, int m, int r)
	{
		int a = m-l;
		int b = r-m;
		int c = r-l;
		pair<int,int> A[a], B[b], C[c];
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
	        while(idx<b && B[idx].first < A[n-l].first)
	        {
	            cnt++;
	            idx++;
	        }
	        counts[arr[n].second]+=cnt;
	    }
		while(i<a && j<b)
		{
			if(A[i].first < B[j].first)
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

	void merge_sort(vector<pair<int,int>> &A, int l, int r)
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
    
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        int i = 0;
        counts.resize(N, 0);
        for(int n = 0; n<N; n++)
            elements.push_back({nums[n], n});
        merge_sort(elements, 0, N);
        return counts;
    }
};