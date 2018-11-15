/*
ID: code_lite
PROG: CHEFADD
LANG: C++                  
*/

#include <bits/stdc++.h> 

typedef long long int lli;

using namespace std; 

long long lookup[32][32][32][2];
string toBinary(lli n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

lli count1(lli a)
{
  lli a_count=0;
  while(a)
  {
    a_count += a&1;
    a/=2;
  }
  return a_count;
}

long long int my_count;
string S;

long long int recurse(int index, int a_count, int b_count, int carry)
{
  if(lookup[index+1][a_count][b_count][carry] != -1)
  {
    return lookup[index+1][a_count][b_count][carry];
  }
  lookup[index+1][a_count][b_count][carry]=0;
  if(index == -1)
  {
    if(a_count == 0 && b_count == 0 && carry == 0)
    {
      lookup[index+1][a_count][b_count][carry]= 1;
    }
    return lookup[index+1][a_count][b_count][carry];
  }
  if(a_count == 0 || b_count == 0)
  {
    if(a_count == 0 && b_count != 0)
    {
      if(carry == 1)
      {
        if(S[index] == '0')
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count-1, 1);
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
      else
      {
        if(S[index] == '1')
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count-1, 0);
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
    }
    else if(b_count == 0 && a_count != 0)
    {
      if(carry == 1)
      {
        if(S[index] == '0')
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count, 1);
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
      else
      {
        if(S[index] == '1')
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count, 0);
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
    }
    else
    {
      if(carry == 1)
      {
        if(S[index] == '0')
        {
          return 0;
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
      else
      {
        if(S[index] == '1')
        {
          return 0;
        }
        else
        {
          lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        }
      }
    }
  }
  else
  {
    if(carry == 0)
    {
      if(S[index] == '0')
      {
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count-1, 1);
      }
      else
      {
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count, 0);
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count-1, 0);
      }
    }
    else
    {
      if(S[index] == '0')
      {
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count, 1);
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count-1, 1);
      }
      else
      {
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count, b_count, 0);
        lookup[index+1][a_count][b_count][carry]+=recurse(index-1, a_count-1, b_count-1, 1);
      }
    }
  }
  return lookup[index+1][a_count][b_count][carry];
}

int main()
{
    lli T;
    cin>>T;
    while(T--)
    {
      lli a,b,c;
      lli a_count=0,b_count=0;
      cin>>a>>b>>c;

      my_count = 0;

      a_count = count1(a);
      b_count = count1(b);

      S = toBinary(c);
      for(long long i=0;i<32;i++)
      {
        for(long long j=0;j<32;j++)
        {
          for(long long k=0;k<32;k++)
          {
            lookup[i][j][k][0]=-1;
            lookup[i][j][k][1]=-1;
          }     
        }
      }

      my_count=recurse(S.length()-1, a_count, b_count, 0);
      cout<<my_count<<"\n";
    }
    return 0;
}
