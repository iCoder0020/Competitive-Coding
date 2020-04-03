#include <bits/stdc++.h>

using namespace std;

#define int long long

int lpl(string S)
{
	string rev=S,str=S;

    int M = S.size(), ans=1;
    if(M == 0 || M == 1)    
    	ans=M; 
    reverse(rev.begin(), rev.end());
    S+='@';
    S+=rev;
    int N=S.size(), Z[N+4], l=0, r=0;
    for(int i=1; i<N; i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<N && S[r-l]==S[r])
                r++;
            Z[i]=r-l,r--;
        }
        else
        {
            int k=i-l;
            if(Z[k]<r-i+1)
                Z[i]=Z[k];
            else
            {
                l=i;
                while(r<N && S[r-l]==S[r])
                    r++;
                Z[i]=r-l,r--;
            }
        }
    }

    for(int i=M+1; i<N; i++)
        if(2*Z[i]>=2*M-i && Z[i]>ans)
            ans=Z[i];

    return ans;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S;
		cin>>S;
		int i = 0, j = S.length()-1;
		string T1 = "", T2 = "";
		while(i<=j)
		{
			if(i == j)
				T1 += S[i];
			else if(S[i] == S[j])
			{
				T1 += S[i];
				T2 += S[j];
			}
			else
				break;

			i++;
			j--;
		}
		if(j-i >= 0)
		{
			int x = lpl(S.substr(i, j-i));
			string P = S.substr(i+1, j-i);
			reverse(P.begin(), P.end());
			int y = lpl(P);


			if(x>=y)
				T1 += S.substr(i, x);
			else
				T2 += P.substr(0, y);
		}
		reverse(T2.begin(), T2.end());
		cout<<T1+T2<<endl;
	}
	return 0;
}
