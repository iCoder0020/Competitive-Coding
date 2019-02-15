/*
ID: iCoder0020
PROG: Truck Tour
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int truckTour(vector<vector<int>> petrolpumps) 
{
    long long int x = 0;
    int N = petrolpumps.size();
    int start = -1;
    int i,j;
    int count;
    for(i = 0; i<N; i++)
    {
        x = petrolpumps[i][0] - petrolpumps[i][1];
        if(x >= 0)
        {
            count = 1;
            for(j = (i+1)%N; count<N; j = (j+1)%N, count++) 
            {
                if(x + petrolpumps[j][0] - petrolpumps[j][1] < 0)
                {
                    i = j;
                    break;
                }
                x += petrolpumps[j][0] - petrolpumps[j][1];
            }
            if(count == N)
            {
                start = i;
                break;
            }
        }
    } 
    return start;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
