/*
ID: ishan_sang
PROG: VSN
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T;
    long double p[3], q[3], d[3], c[3], r, f[3], g[3], coefficient[3], t_min_minus, t_min_plus, t_min;
    cin>>T;
    for(int t=0; t<T; t++)
    {
        for(int i=0; i<3; i++)
        {
            cin>>p[i];
        }
        for(int i=0; i<3; i++)
        {
            cin>>q[i];
        }
        for(int i=0; i<3; i++)
        {
            cin>>d[i];
        }
        for(int i=0; i<3; i++)
        {
            cin>>c[i];
        }
        cin>>r;
        for(int i=0; i<3; i++)
        {
            f[i] = p[i] - c[i];
            g[i] = q[i] - p[i];
        }

        coefficient[2] = (r*r)*(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
        coefficient[2] += (2)*(f[0]*f[1]*d[0]*d[1] + f[1]*f[2]*d[1]*d[2] + f[2]*f[0]*d[2]*d[0]);
        coefficient[2] -= (f[0]*f[0])*(d[1]*d[1] + d[2]*d[2]);
        coefficient[2] -= (f[1]*f[1])*(d[2]*d[2] + d[0]*d[0]);
        coefficient[2] -= (f[2]*f[2])*(d[0]*d[0] + d[1]*d[1]);

        coefficient[1] = (r*r)*(d[0]*g[0] + d[1]*g[1] + d[2]*g[2]);
        coefficient[1] += (f[0]*g[0]*f[1]*d[1] + f[0]*d[0]*f[1]*g[1] + f[1]*g[1]*f[2]*d[2] + f[1]*d[1]*f[2]*g[2] + f[2]*g[2]*f[0]*d[0] + f[2]*d[2]*f[0]*g[0]);
        coefficient[1] -= (f[0]*f[0])*(g[1]*d[1] + g[2]*d[2]);
        coefficient[1] -= (f[1]*f[1])*(g[2]*d[2] + g[0]*d[0]);
        coefficient[1] -= (f[2]*f[2])*(g[0]*d[0] + g[1]*d[1]);
        coefficient[1] *= 2;

        coefficient[0] = (r*r)*(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);
        coefficient[0] += (2)*(f[0]*f[1]*g[0]*g[1] + f[1]*f[2]*g[1]*g[2] + f[2]*f[0]*g[2]*g[0]);
        coefficient[0] -= (f[0]*f[0])*(g[1]*g[1] + g[2]*g[2]);
        coefficient[0] -= (f[1]*f[1])*(g[2]*g[2] + g[0]*g[0]);
        coefficient[0] -= (f[2]*f[2])*(g[0]*g[0] + g[1]*g[1]);

        if(coefficient[2] == 0)
        {
            t_min = ((-1.0)*coefficient[0])/(coefficient[1]);
        }
        else
        {
            t_min_plus = (-(1.0)*coefficient[1] + sqrt(coefficient[1]*coefficient[1] - (4.0)*coefficient[0]*coefficient[2]))/(2*coefficient[2]);
            t_min_minus = (-(1.0)*coefficient[1] - sqrt(coefficient[1]*coefficient[1] - (4.0)*coefficient[0]*coefficient[2]))/(2*coefficient[2]);
            if(t_min_minus > 0 && (t_min_minus<t_min_plus || t_min_plus<=0))
            {
                t_min = t_min_minus;
            }
            else
            {
                t_min = t_min_plus;
            }
        }
        cout<<t_min<<"\n";
    }
    return 0;
}
