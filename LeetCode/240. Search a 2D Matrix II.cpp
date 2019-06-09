/*
ID: iCoder0020
PROG: Search a 2D Matrix II
LANG: C++                  
*/

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int N = matrix.size();
        if(N == 0)
            return false;
        int M = matrix[0].size();
        if(M == 0)
            return false;
        for(int n = 0; n<N; n++)
        {
            for(int m = M-1; m>=0; m--)
            {
                if(matrix[n][m] == target)
                    return true;
                else if(matrix[n][m] < target)
                    break;
                else
                    M--;
            }
        }
        return false;
    }
};