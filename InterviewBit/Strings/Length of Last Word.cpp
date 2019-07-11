/*
ID: ishan-sang
PROG: Length of Last Word
LANG: C++                  
*/

int Solution::lengthOfLastWord(const string A) 
{
    int N = A.size();
    int i = 0;
    string word;
    int start, end;
    while(i<N)
    {
        while(i<N && A[i] == ' ')
            i++;
        start = i;
        while(i<N && A[i] != ' ')
            i++;
        end = i;
        word = A.substr(start, end-start);
        while(i<N && A[i] == ' ')
            i++;
    }
    return word.size();
}

