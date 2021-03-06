/*
ID: iCoder0020
PROG: Ice Cream Parlor
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) 
{
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());
    int i = -1,j = -1;
    for(int l: arr2)
    {
        if(binary_search(arr2.begin(), arr2.end(), m-l))
        {
            for(int n = 0; n<arr.size(); n++)
            {
                if(arr[n] == l && i == -1)
                {
                    i = n;
                }
                else if(arr[n] == m-l && j == -1)
                {
                    j = n;
                }
                if(i!=-1 && j!=-1)
                {
                    break;
                }
            }
            break;
        }
    }
    vector<int>result;
    result.push_back(i+1);
    result.push_back(j+1);
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = icecreamParlor(m, arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
