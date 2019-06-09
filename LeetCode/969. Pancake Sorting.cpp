/*
ID: iCoder0020
PROG: Pancake Sorting
LANG: C++                  
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        int maxm = N;
        vector<int>ans;
        int k;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<maxm; j++)
            {
                if(A[j] == maxm)
                {
                    k = j+1;
                    break;
                }
            }
            reverse(A.begin(), A.begin()+k);            
            reverse(A.begin(), A.begin()+maxm);
            ans.push_back(k);
            ans.push_back(maxm);
            maxm--;
        }
        return ans;
    }
};