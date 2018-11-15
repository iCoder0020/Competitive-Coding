/*
ID: code_lite
PROG: CHQUEENS
LANG: C++                  
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin>>T;
  for(int t = 0; t<T; t++)
  {
    int N,M;
    int X,Y;
    cin>>N>>M;
    cin>>X>>Y;
    long long int count = 0;
    long long int rev_count;
    for(int x = 0; x<N; x++)
    {
      for(int y = 0; y<M; y++)
      {
        int c1 = x+y, c2 = x-y;
        int tempx, tempy;
        rev_count = 0;
        if(x != X-1 || y != Y-1)
        {
          if(!(x == X-1 || y == Y-1 || x+y == X+Y-2 || x-y == X-Y))
          {
            rev_count++;
          }
          
          rev_count += (N-1-x) + (x-0) + (M-1-y) + (y-0) + 1;
          tempy = c1;
          if(tempy < M)
          {
            rev_count += tempy - y;
          }
          else
          {
            tempx = c1-(M-1);
            if(tempx >= 0)
            {
              rev_count += x - tempx;
            }
          }
          tempy = c1-(N-1);
          if(tempy >= 0)
          {
            rev_count += y - tempy;
          }
          else
          {
            tempx = c1;
            if(tempx < N)
            {
              rev_count += tempx - x;
            }
          }
          tempy = (N-1)-c2;
          if(tempy < M)
          {
            rev_count += tempy - y;
          }
          else
          {
            tempx = c2+(M-1);
            if(tempx < N)
            {
              rev_count += tempx - x;
            }
          }
          tempy = -1*c2;
          if(tempy >= 0)
          {
            rev_count += y - tempy;
          }
          else
          {
            tempx = c2;
            if(tempx >= 0)
            {
              rev_count += x - tempx;
            }
          }
          count += (M*N)-rev_count;

        }
        
      }
    }
    count += 2*(N-X)*(X-1);
    count += 2*(M-Y)*(Y-1);

    int c1 = (X-1)+(Y-1);
    int c2 = (X-1)-(Y-1);

    int x = X-1;
    int y = Y-1;

    int tempx,tempy;

    int p1,p2;

    tempy = c1;
    if(tempy < M)
    {
      p1= tempy - y;
    }
    else
    {
      tempx = c1-(M-1);
      if(tempx >= 0)
      {
        p1= x - tempx;
      }
    }

    tempy = c1-(N-1);
    if(tempy >= 0)
    {
      p2 = y - tempy;
    }
    else
    {
      tempx = c1;
      if(tempx < N)
      {
        p2 = tempx - x;
      }
    }

    count+=2*p1*p2;

    tempy = (N-1)-c2;
    if(tempy < M)
    {
      p1 = tempy - y;
    }
    else
    {
      tempx = c2+(M-1);
      if(tempx < N)
      {
        p1 = tempx - x;
      }
    }

    tempy = -1*c2;
    if(tempy >= 0)
    {
      p2 = y - tempy;
    }
    else
    {
      tempx = c2;
      if(tempx >= 0)
      {
        p2 = x - tempx;
      }
    }

    count+=2*p1*p2;
    cout<<count<<endl;
  }
  return 0;
}