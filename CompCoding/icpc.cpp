#include<bits/stdc++.h>
using namespace std;
#define int long long

double maxA = -1;
int x1, x2, x3, y1, y2, y3;
bool f(int A, int B, int C)
{
    int X1 = 10, Y1 = 10;
    int X2, Y2, X3, Y3;
    if((A+B-C)%2 == 0 && (B+C-A)%2 == 0) {
        X2 = X1 + (A+B-C)/2, Y2 = abs(Y1 + (B+C-A)/2);
        X3 = X1 + A, Y3 = Y1;
        if(X2<X1 || X2>X3) return false;
    }
    else return false;

    double A = abs(0.5*(X2-X1)*(Y2-Y1));
    if(A>maxA)
    {
        maxA = A;
        x1 = X1;
        x2 = X2;
        x3 = X3;
        y1 = Y1;
        y2 = Y2;
        y3 = Y3;
    }

    return true;
}

int32_t main() {
  int TC;
  cin>>TC;
  while(TC--) {
      int A[3];
      for(int i=0; i<3; ++i) cin>>A[i];
      bool done = false;
      for(int i=0; i<3; ++i)
      {
          for(int j=0; j<3; ++j)
          {
              if(j==i) continue;
              for(int k=0; k<3; ++k)
              {
                if(k==j || k==i) continue;
                if(f(A[i], A[j], A[k]))
                    done = true;
              }
          }
      }
      if(!done) cout<<"NO\n";
      else {
    
          cout<<"YES\n";
          cout<<x1<<" "<<y1<<"\n";
          cout<<x2<<" "<<y2<<"\n";
          cout<<x3<<" "<<y3<<"\n";

      }
  }
  return 0;
}