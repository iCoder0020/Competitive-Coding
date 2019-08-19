/*
ID: ishan-sang
PROG: Smallest Multiple With 0 and 1
LANG: C++                  
*/

string Solution::multiple(int A) 
{
    if(A == 0)
        return "0";
    vector<int>prev(A, 0);
    vector<int>bit(A, 0);
    queue<pair<int,pair<int,int>>>Q;
    vector<bool>v(A, false);
    Q.push({1%A, {0, 1}});
    v[1%A]=true;
    while(!Q.empty())
    {
        int temp = Q.front().first;
        prev[temp] = Q.front().second.first;
        bit[temp] = Q.front().second.second;
        
        // cout<<temp<<" "<<prev[temp]<<" "<<bit[temp]<<endl;
        if(temp == 0)
            break;
        Q.pop();
        int rem = (temp*10)%A;
        if(!v[rem])
        {
            Q.push({rem, {temp, 0}});
            v[rem]=true;
        }
        rem = (rem+1)%A;
        if(!v[rem])
        {
            Q.push({rem, {temp, 1}});
            v[rem]=true;
        }
    }
    
    int curr = 0;
    string ans="";
    do
    {
        ans += (bit[curr]+'0');
        curr = prev[curr];
    }while(curr);
    reverse(ans.begin(), ans.end());
    return ans;
}
