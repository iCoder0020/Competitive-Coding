/*
ID: iCoder0020
PROG: Almost Sorted
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int N = arr.size();
    vector<int>v;
    for(int n = 0; n<N-1; n++)
    {
        if(arr[n] > arr[n+1])
            v.push_back(n);
    }
    if(v.size() == 0)
    {
        cout<<"yes"<<endl;
        return;
    }
    else if(v.size() == 1)
    {
        int n = v[0];
        if((n+2>=N || arr[n+2] > arr[n]) && (n-1<0 || arr[n+1] > arr[n-1]))
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<n+1<<" "<<n+2<<endl;
            return;
        }
        else
        {
            cout<<"no"<<endl;
            return;
        }
    }
    else if(v.size() == 2)
    {
        int i = v[0];
        int j = v[1]+1;
        if((i-1<0 || arr[i-1] < arr[j]) && (i+1>=N || arr[i+1] > arr[j]) && (j-1<0 || arr[j-1] < arr[i]) && (j+1>=N || arr[j+1] > arr[i]))
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<v[0]+1<<" "<<v[1]+2<<endl;
            return;
        }
        else
        {
            cout<<"no"<<endl;
            return;
        }
    }
    else
    {
        for(int i = 0; i<v.size()-1; i++)
        {
            if(v[i+1] - v[i] != 1)
            {
                cout<<"no"<<endl;
                return;
            }
        }
        int i = v[0];
        int j = v[v.size()-1];
        if((i-1<0 || arr[i-1] < arr[j+1])&&(j+2>=N || arr[j+2] > arr[i]))
        {
            cout<<"yes"<<endl;
            cout<<"reverse "<<v[0]+1<<" "<<v[v.size()-1]+2<<endl;
            return;
        }
        else
        {
            cout<<"no"<<endl;
            return;
        }
    }
}

int main()
{
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

    almostSorted(arr);

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
