/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector < pair <int, int> >P(N/2);
    int i;
    for(i = 0; i<N/2; i++)
    {
        P[i].first = 2*i+1;
        P[i].second = 2*(i+1);
    }
    do
    {
        for(i = 0; i<N/2; i++)
        {
            cout<<P[i].first<<P[i].second<<" ";
        }
        cout<<"\n";
    }while(next_permutation(P.begin(), P.end()));
    return 0;
}*//*
ID: ishansa2
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("wormhole.out");
ifstream fin("wormhole.in");

int N;
int i,j,p,q,check_i,check_j,check_k,c,answered=0;
int count_steps,num[12],num_limit[12],t[12],wormholes_visited_id[12];
int num_infinite_cycle=0;
int pair_up_chart[10395][12];

struct cow
{
	long long x;
	long long y;
};

cow C;

struct wormhole
{
	int WH_id;
	int WH_pair_id;
	long long x;
	long long y;
};

wormhole W[12];

void input()
{
	fin>>N;
	for(i=0;i<N;i++)
	{
		fin>>W[i].x>>W[i].y;
	}
}

void swap_num(long long &a, long long &b)
{
	a+=b;
	b=a-b;
	a-=b;
}

void sort_wrt_x()
{
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(W[i].x>W[j].x)
			{
				swap_num(W[i].x,W[j].x);
				swap_num(W[i].y,W[j].y);
			}
		}
	}
}

void setup_id()
{
	for(i=0;i<N;i++)
	{
		W[i].WH_id=i+1;
	}
}

int num_all_combinations()
{
	int product=1;
	for(int i=1;i<N;i+=2)
        {
                product*=i;
        }
        return product;
}

int row_check(int n)
{
        for(int i=0;i<q;i++)
        {
                if(n==pair_up_chart[p][i])
                {
                        return 0;
                }
        }
        return 1;
}

int full_check()
{
        int check;
        for(check_j=0;check_j<N;check_j++)
        {
                if(pair_up_chart[p][check_j]==0)
                {
                        return 1;
                }
        }
        for(check_i=0;check_i<p;check_i++)
        {
                check=0;
                for(check_j=0;check_j<N;check_j+=2)
                {
                        for(check_k=0;check_k<N;check_k+=2)
                        {
                               if(((pair_up_chart[check_i][check_k]==pair_up_chart[p][check_j])&&(pair_up_chart[check_i][(check_k)+1]==pair_up_chart[p][check_j+1])))
                                {
                                        check++;
                                        break;
                                }
                                if(((pair_up_chart[check_i][(check_k)+1]==pair_up_chart[p][check_j])&&(pair_up_chart[check_i][check_k]==pair_up_chart[p][check_j+1])))
                                {
                                        check++;
                                        break;
                                }
                        }

                }
                if(check==N/2)
                {
                        return 1;
                }
        }
        return 0;

}

void prepare_for_pairing()
{
        for(i=0;i<N;i++)
        {
                if(i==0)
                {
                        num[i]=1;
                        num_limit[i]=1;
                }
                if(i!=0)
                {
                        num[i]=2;
                        num_limit[i]=N;
                }
                if(i==N-1)
                {
                        i++;
                        while(i<=11)
                        {
                                num[i]=0;
                                num_limit[i]=0;
                                i++;
                        }
                }
        }
}

void take_cow_to_unlucky_position()
{
	C.x=W[i].x;
	C.y=W[i].y;
	wormholes_visited_id[c]=W[i].WH_id;
	c++;
}

int check_repetition()
{
        for(int i=0;i<c;i++)
        {
                for(int j=i+1;j<c;j++)
                {
                        if(wormholes_visited_id[i]==wormholes_visited_id[j])
                        {
                                return 1;
                        }
                }
        }
        return 0;
}

int wormhole_check()
{
	int k;
	for(int i=0;i<N;i++)
	{
		if(C.x==W[i].x&&C.y==W[i].y)
		{
			wormholes_visited_id[c]=W[i].WH_id;
			c++;
			for(k=0;k<N;k++)
                        {
                                if(W[i].WH_pair_id==W[k].WH_id)
                                {
                                        C.x=W[k].x;
                                        C.y=W[k].y;
                                        break;
                                }
                        }
                        wormholes_visited_id[c]=W[k].WH_id;
			c++;
			if(check_repetition())
                        {
                                num_infinite_cycle++;
                                return 0;
                        }
			count_steps=0;
			return 1;
		}
	}
}

void start_journey()
{
	for(count_steps=0;count_steps<=W[N-1].x-W[0].x;count_steps++)
	{
		C.x++;
		if(!wormhole_check())
                {
                        answered=1;
                        break;
                }
	}
}

void lets_go()
{
        for(i=0;i<N;i++)
        {
                c=0;
                take_cow_to_unlucky_position();
                start_journey();
                if(answered==1)
                {
                        answered=0;
                        break;
                }
        }
}

void link()
{
        for(p=0;p<num_all_combinations();p++)
        {
                for(int l1=0;l1<N;l1+=2)
                {
                        for(int l2=0;l2<N;l2++)
                        {
                                if(pair_up_chart[p][l1]==W[l2].WH_id)
                                {
                                        W[l2].WH_pair_id=pair_up_chart[p][l1+1];
                                        for(int l3=0;l3<N;l3++)
                                        {
                                                if(pair_up_chart[p][l1+1]==W[l3].WH_id)
                                                {
                                                        W[l3].WH_pair_id=pair_up_chart[p][l1];
                                                        break;
                                                }
                                        }
                                }
                        }
                }
                lets_go();
        }
}

void output()
{
	fout<<num_infinite_cycle<<"\n";
}

void pair_up()
{
	p=0;
        prepare_for_pairing();
        q=0;
        for(t[0]=num[0];t[0]<=num_limit[0];t[0]++)
        {
                for(t[1]=num[1];t[1]<=num_limit[1];t[1]++)
                {
                        for(t[2]=num[2];t[2]<=num_limit[2];t[2]++)
                        {
                                for(t[3]=num[3];t[3]<=num_limit[3];t[3]++)
                                {
                                        for(t[4]=num[4];t[4]<=num_limit[4];t[4]++)
                                        {
                                                for(t[5]=num[5];t[5]<=num_limit[5];t[5]++)
                                                {
                                                        for(t[6]=num[6];t[6]<=num_limit[6];t[6]++)
                                                        {
                                                                for(t[7]=num[7];t[7]<=num_limit[7];t[7]++)
                                                                {
                                                                        for(t[8]=num[8];t[8]<=num_limit[8];t[8]++)
                                                                        {
                                                                                for(t[9]=num[9];t[9]<=num_limit[9];t[9]++)
                                                                                {
                                                                                        for(t[10]=num[10];t[10]<=num_limit[10];t[10]++)
                                                                                        {
                                                                                                for(t[11]=num[11];t[11]<=num_limit[11];t[11]++)
                                                                                                {
                                                                                                        for(q=0;q<N;q++)
                                                                                                        {
                                                                                                                if(row_check(t[q]))
                                                                                                                {
                                                                                                                        pair_up_chart[p][q]=t[q];
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                        pair_up_chart[p][q]=0;
                                                                                                                }
                                                                                                        }
                                                                                                        if(full_check()==0)
                                                                                                        {
                                                                                                                p++;
                                                                                                        }
                                                                                                        if(p==num_all_combinations())
                                                                                                        {
                                                                                                               link();
                                                                                                               output();
                                                                                                               return;
                                                                                                        }
                                                                                                }
                                                                                        }
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
}


int main()
{
	input();
	sort_wrt_x();
	setup_id();
	pair_up();
	return 0;
}
