/*
ID: code_lite
PROG: TEAMMATE
LANG: C++                  
*/

#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAX_LENGTH 1000005

typedef long long int li;

li even_arr[MAX_LENGTH] = {0};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  li T;
  cin>>T;
  even_arr[0] = 1;
  for(li i = 2; i<MAX_LENGTH; i+=2) 
  {
    even_arr[i] = (((even_arr[i-2])%MOD)*((i-1)%MOD))%MOD;
  }

  for(li t = 0; t<T; t++)
  {
    li N;
    li skill_arr[MAX_LENGTH] = {0};
    li temp;
    li max_skill = 0;
    cin>>N;
    for(li n = 0; n<N; n++)
    {
      cin>>temp;
      skill_arr[temp]++;
      if(temp > max_skill)
      {
        max_skill = temp;
      }
    }
    li index = max_skill;
    li index2;
    li count = 1;

    while(true)
    {
      index2 = index - 1;
      while(skill_arr[index2] == 0 && index2 > 0)
      {
        index2--;
      }
      if(skill_arr[index]%2 == 0)
      {
        count = ((count%MOD) * ((even_arr[skill_arr[index]])%MOD))%MOD;
      }
      else
      {
        if(skill_arr[index] > 1)
        {
          count = ((count%MOD) * ((even_arr[skill_arr[index]-1])%MOD))%MOD;
          count = ((count%MOD) * ((skill_arr[index]%MOD)))%MOD;
        }
        count = ((count%MOD)) * ((skill_arr[index2]%MOD))%MOD;
        skill_arr[index2]--;
      }
      index = index2;
      if(index <= 0)
      {
        break;
      }
      while(skill_arr[index] == 0 && index > 0)
      {
        index--;
      }
      if(index <=0 )
      {
        break;
      }
    }
    cout<<count<<"\n";
  }
  return 0;
}