/*
ID: code_lite
PROG: PERIODIC
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li GCD(li a, li b)
{
  if(b>a)
  {
    return GCD(b, a);
  }
  if(b == 0)
  {
    return a;
  }
  else
  {
    return GCD(b, a%b);
  }
}

int main()
{
    int T;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        int N;
        cin>>N;

        int A[N];
        int max = 0;

        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
            if(max < A[n])
            {
                max = A[n];
            }
        }

        int pos_1_index = -1;

        for(int i = 0; i<N; i++)
        {
            if(A[i]>0)
            {
                pos_1_index = i;
                break;
            }
        }

        if(pos_1_index == -1)
        {
            cout<<"inf\n";
        }

        else
        {
            int pos_2_index = -1;

            for(int i = pos_1_index+1; i<N; i++)
            {
                if(A[i]>0)
                {
                    pos_2_index = i;
                    break;
                }
            }

            if(pos_2_index == -1)
            {
                cout<<"inf\n";
            }

            else
            {
                int pos_arr[N]={0};
                int mod_index = -1;

                pos_arr[pos_1_index] = A[pos_1_index];

                for(int i = pos_1_index+1; i<N; i++)
                {
                    pos_arr[i] = pos_arr[i-1] + 1;
                    if(pos_arr[i]!=A[i] && A[i]!=-1 && mod_index==-1)
                    {
                        mod_index = i;
                    }
                }


                if(mod_index == -1)
                {
                    cout<<"inf\n";
                }

                else
                {
                    int K;
                    int K_new;
                    bool not_possible = false;
                    K = (A[pos_1_index]-A[mod_index]) + (mod_index - pos_1_index);
                    if(K<max)
                    {
                        cout<<"impossible\n";
                    }

                    else
                    {
                        int i;
                        for(i = mod_index; i<N; i++)
                        {
                            pos_arr[i] = (pos_arr[i]-1)%K + 1;
                            if(pos_arr[i]!=A[i] && A[i]!=-1)
                            {
                              K_new = (A[mod_index]-A[i]) + (i - mod_index);
                              K_new = GCD(K, K_new);
                              if(K_new<max)
                              {
                                not_possible = true;
                                cout<<"impossible\n";
                                break;
                              }
                              else
                              {
                                K = K_new;
                                mod_index = i;
                                i--;
                              }
                            } 
                        }

                        if(i == N && not_possible == false)
                        {
                            cout<<K<<"\n";
                        }
                    }
                }
            }
        }
    }
}