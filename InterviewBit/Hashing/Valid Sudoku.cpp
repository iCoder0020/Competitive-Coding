/*
ID: ishan-sang
PROG: Valid Sudoku
LANG: C++                  
*/

int Solution::isValidSudoku(const vector<string> &A) 
{
    int N = A.size();
    vector<vector<bool>> rows(N, vector<bool>(10,false));
    vector<vector<bool>> cols(N, vector<bool>(10,false));
    int sq_N = sqrt(N);
    vector<vector<vector<bool>>> blocks(sq_N, vector<vector<bool>>(sq_N, vector<bool>(10, false)));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(A[i][j] != '.')
            {
                int num = A[i][j] - '0';
                if(rows[i][num])
                    return 0;
                rows[i][num] = true;
                if(cols[j][num])
                    return 0;
                cols[j][num] = true;
                int i_bl = (i/sq_N);
                int j_bl = (j/sq_N);
                if(blocks[i_bl][j_bl][num])
                    return 0;
                blocks[i_bl][j_bl][num] = true;
            }
        }
    }
    return 1;
}
