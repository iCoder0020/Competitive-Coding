/*
ID: ishan-sang
PROG: Reverse the String
LANG: C++                  
*/

void Solution::reverseWords(string &A) 
{
    vector<string>words;
    int N = A.size();
    int i = 0;
    int start, end;
    while(i<N)
    {
        while(i<N && A[i] == ' ')
            i++;
        start = i;
        while(i<N && A[i]!= ' ')
            i++;
        end = i;
        words.push_back(A.substr(start, end-start));
        while(i<N && A[i] == ' ')
            i++;
    }
    A = "";
    for(int n = words.size()-1; n>=0; n--)
    {
        A += words[n];
        if(n != 0)
            A += ' ';
    }
}
