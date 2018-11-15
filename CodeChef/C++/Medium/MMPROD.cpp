/*
ID: ishan_sang
PROG: MMPROD
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
#define MOD 1000000007

bool desc(li a, li b)
{
	return a>b;
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		li K,N;
		cin>>N>>K;
		vector <li> neg;
		vector <li> pos;
		li count_zero = 0;
		li temp;
		
		for(li n = 0; n<N; n++)
		{
			cin>>temp;
			if(temp < 0)
			{
				neg.push_back(temp);
			}
			else if(temp > 0)
			{
				pos.push_back(temp);
			}
			else
			{
				count_zero++;
			}
		}

		li pos_index = 0;
		li neg_index = 0;
		li pos_product = 1;
		li neg_product = 1;
		li product = 1;
		
		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end(), desc);


		if(K == N)
		{
			if(count_zero!=0)
			{
				product = 0;
			}
			else
			{
				for(li neg_index = 0; neg_index<neg.size(); neg_index++)
				{
					product = ((product%MOD + MOD)%MOD * (neg[neg_index]%MOD + MOD)%MOD)%MOD;
				}
				for(li pos_index = 0; pos_index<pos.size(); pos_index++)
				{
					product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
				}
			}
		}

		else if(pos.size()+neg.size()<K)
		{
			product = 0;
		}

		else if(pos.size() == 0)
		{
			if(K%2 == 0)
			{
				for(li neg_index = 0; neg_index<K; neg_index++)
				{
					product = ((product%MOD + MOD)%MOD * (neg[neg_index]%MOD + MOD)%MOD)%MOD;
				}
			}
			else
			{
				if(count_zero!=0)
				{
					product = 0;
				}
				else
				{
					for(li neg_index = neg.size()-1; neg_index>=neg.size()-K; neg_index--)
					{
						product = ((product%MOD + MOD)%MOD * (neg[neg_index]%MOD + MOD)%MOD)%MOD;
					}
				}
			}
		}

		else if(neg.size() == 0)
		{
			for(li pos_index = 0; pos_index<K; pos_index++)
			{
				product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
			}
		}

		else if(neg.size() == 1)
		{
			if(pos.size() < K)
			{
				if(count_zero!=0)
				{
					product = 0;
				}
				else
				{
					product = ((product%MOD + MOD)%MOD * (neg[0]%MOD + MOD)%MOD)%MOD;
					for(li pos_index = pos.size()-1; pos_index>=pos.size()-K+1; pos_index--)
					{
						product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
					}
				}
			}
			else
			{
				for(li pos_index = 0; pos_index<K; pos_index++)
				{
					product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
				}
			}
		}

		else
		{
			while(K)
			{
				pos_product = 1;
				neg_product = 1;
				if(K == 1)
				{
					if(pos_index < pos.size())
					{
						product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
						pos_index++;
					}
					else if(count_zero!=0)
					{
						product = 0;
					}
					else
					{
						product = neg[neg.size()-1];
						for(li pos_index = pos.size()-1; pos_index>=pos.size()-K+1; pos_index--)
						{
							product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
						}
					}
					K--;
				}
				
				else if(K == 3)
				{
					if(neg_index+1 <= neg.size()-1)
					{
						neg_product = ((neg[neg_index]%MOD + MOD)%MOD * (neg[neg_index+1]%MOD + MOD)%MOD)%MOD;
						if(pos_index+1 <= pos.size()-1)
						{
							if(neg_product > pos[pos_index+1])
							{
								product = ((product%MOD + MOD)%MOD * (neg_product%MOD + MOD)%MOD)%MOD;
								product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
								pos_index++;
								neg_index += 2;
							}
							else
							{
								pos_product = (pos[pos_index]%MOD * pos[pos_index+1]%MOD)%MOD;
								product = ((product%MOD + MOD)%MOD * (pos_product%MOD + MOD)%MOD)%MOD;
								product = ((product%MOD + MOD)%MOD * (pos[pos_index+2]%MOD + MOD)%MOD)%MOD;
								pos_index += 3;
							}
						}
						else
						{
							product = ((product%MOD + MOD)%MOD * (neg_product%MOD + MOD)%MOD)%MOD;
							product = ((product%MOD + MOD)%MOD * (pos_product%MOD + MOD)%MOD)%MOD;
							pos_index++;
							neg_index += 2;
						}
					}
					else if(pos_index+2 <= pos.size()-1)
					{
						pos_product = (pos[pos_index]%MOD * pos[pos_index+1]%MOD)%MOD;
						product = ((product%MOD + MOD)%MOD * (pos_product%MOD + MOD)%MOD)%MOD;
						product = ((product%MOD + MOD)%MOD * (pos[pos_index+2]%MOD + MOD)%MOD)%MOD;
						pos_index += 3;
					}
					else
					{
						product = 0;
					}
					K -= 3;
				}

				else
				{
					if(neg_index == neg.size() || neg_index == neg.size()-1)
					{
						if(pos_index+(K-1) <= pos.size()-1)
						{
							while(K)
							{
								product = ((product%MOD + MOD)%MOD * (pos[pos_index]%MOD + MOD)%MOD)%MOD;
								pos_index++;
								K--;
							}
							pos_index += K;
							K = 2;
						}
						else
						{
							product = 0;
						}
					}
					else if((neg.size()-neg_index) >= 2)
					{
						neg_product = ((neg[neg_index]%MOD + MOD)%MOD * (neg[neg_index+1]%MOD + MOD)%MOD)%MOD;
						if(pos_index+1 <= pos.size()-1)
						{
							pos_product = (pos[pos_index]%MOD * pos[pos_index+1]%MOD)%MOD;
							if(pos_product > neg_product)
							{
								product = ((product%MOD + MOD)%MOD * (pos_product%MOD + MOD)%MOD)%MOD;
								pos_index += 2;
							}
							else
							{
								product = ((product%MOD + MOD)%MOD * (neg_product%MOD + MOD)%MOD)%MOD;
								neg_index += 2;
							}
						}
						else
						{
							product = ((product%MOD + MOD)%MOD * (neg_product%MOD + MOD)%MOD)%MOD;
							neg_index += 2;
						}
					}
					K -= 2;
				}
			}
		}
		cout<<(product%MOD + MOD)%MOD<<"\n";
	}
	return 0;
}