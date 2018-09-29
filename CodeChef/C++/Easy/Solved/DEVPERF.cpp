/*
ID: ishan_sang
PROG: DEVPERF
LANG: C++
*/

#include<iostream>

using namespace std;

int main()
{
    int T;
    int n,m;
    int h_min = 0, v_min = 0, h_max = 0, v_max = 0;
    int x,y,time;
    cin>>T;
    for(int t = 0; t < T; t++)
    {
        int flag = 0;
        cin>>n>>m;

        char town_map[n][m];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin>>town_map[i][j];
                if(town_map[i][j] == '*')
                {
                    if(flag == 0)
                    {
                        h_min = j;
                        h_max = j;
                        v_min = i;
                        v_max = i;
                        flag = 2;
                    }
                    else
                    {
                        h_min = (h_min < j) ? h_min : j;
                        h_max = (h_max > j) ? h_max : j;
                        v_min = (v_min < i) ? v_min : i;
                        v_max = (v_max > i) ? v_max : i;
                    }
                }
            }
        }

        if(flag == 0)
        {
            cout<<"0\n";
        }
        else
        {
            x = (v_min + v_max)/2;
            y = (h_min + h_max)/2;

            time = (v_max-x > h_max-y) ? v_max-x : h_max-y;

            cout<<time + 1<<"\n";
        }
    }
    return 0;
}
