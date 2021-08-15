#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    string S;
    cin>>S;
    int a,b;
    cin>>a>>b;
    int i = 0, j = 0;
    for(int n = 0; n<S.length(); n++) {
      if(S[n] == 'A')
        i = n;
      else if(S[n] == 'B')
        j = n;
    }
    if((j-i)%(a+b) == 0)
      cout<<"unsafe";
    else 
      cout<<"safe";
    cout<<endl;
  }
  return 0;
}